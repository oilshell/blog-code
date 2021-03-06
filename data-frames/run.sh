#!/bin/bash
#
# Run the same analysis in 5 languages/libraries.
#
# Usage:
#   ./run.sh <function name>
#
# See README.md for instructions.

set -o nounset
set -o pipefail
set -o errexit

install-r() {
  sudo apt install r-base
}

# NOTE: This takes awhile to download and compile!  But it's worth it.
install-dplyr() {
  sudo Rscript -e 'install.packages(c("dplyr"), repos="https://cran.us.r-project.org")'
}

install-pandas() {
  pip3 install pandas
}

all() {
  echo
  echo '--- With dplyr in R ---'
  echo

  ./with_dplyr.R

  echo
  echo '--- With base R ---'
  echo

  ./with_base_R.R

  echo
  echo '--- With Pandas in Python ---'
  echo

  ./with_pandas.py

  echo
  echo '--- Python without Data Frames ---'
  echo

  ./without_data_frames.py

  echo
  echo '--- With SQL (in shell!) ---'
  echo

  rm -f $DB
  csv2sqlite
  with-sql
}

readonly DB='traffic.sqlite3 '

csv2sqlite() {
  rm -v -f $DB

  sqlite3 $DB <<EOF
.mode csv
.import traffic.csv traffic
EOF

  echo "Imported into $DB"
}

show-db() {
  sqlite3 -header $DB <<EOF
SELECT * FROM traffic;

SELECT '';
SELECT 'Total';
SELECT SUM(num_hits) FROM traffic;
EOF
}

with-sql() {
  sqlite3 $DB <<EOF
SELECT 'Rows:';
SELECT date, url, num_hits FROM traffic;

SELECT '';
SELECT 'Daily Traffic:';  -- silly way to print
SELECT date, SUM(num_hits) FROM traffic GROUP BY date;

SELECT '';
SELECT 'Popular Pages:';

-- Style from blog post
SELECT url,
       SUM(num_hits) * 100.0 / (SELECT SUM(num_hits) FROM traffic)
       AS percentage
FROM traffic
GROUP BY url
ORDER BY percentage DESC;

EOF
}

# This selects from two tables.
# credit to jeb and terminus-est on lobste.rs
# https://lobste.rs/s/hnfc6a/what_is_data_frame_python_r_sql
with-cte() {
  sqlite3 $DB <<EOF
-- Use common table expression.  This table has a single column: the total
-- number of hits in the data set.
WITH     total (num_hits) AS (SELECT SUM(num_hits) FROM traffic)
SELECT   url,
         SUM(traffic.num_hits) * 100.0 / total.num_hits AS percentage
FROM     traffic, total
GROUP BY url
ORDER BY percentage DESC;
EOF
}

# Window functions use the "OVER" keyword.
# https://sqlite.org/windowfunctions.html
# Only available as of version 3.25 as of 9/2018!

sqlite3-new() {
  ~/src/sqlite-autoconf-3330000/sqlite3 -header "$@"
}

with-window() {
  # From peter on lobste.rs:
  # https://lobste.rs/s/0mpcxv/tab_programming_language#c_ewkmc6
  sqlite3-new $DB <<EOF
WITH subtotals AS (
  SELECT url, SUM(num_hits) AS url_hits
  FROM traffic
  GROUP BY url
)
SELECT url,
       -- SUM() OVER () is a window function over the whole table
       url_hits * 100.0 / SUM(url_hits) OVER () AS percentage
FROM subtotals
ORDER BY percentage DESC;
EOF

  echo

  # Factor it into two CTEs

  sqlite3-new $DB <<EOF
WITH
subtotals AS (
  SELECT url, SUM(num_hits) AS url_hits
  FROM traffic
  GROUP BY url
),
percentages AS (
  SELECT url,
         -- SUM() OVER () is a window function over the whole table
         url_hits * 100.0 / SUM(url_hits) OVER () AS percentage
  FROM subtotals
  ORDER BY percentage DESC
)
SELECT * FROM percentages;
EOF

  echo

  return

  # Why isn't this the same?  I can't do it without a CTE?
  # Oh it's because OVER() is respecting GROUP BY first.  The order is very random!
  sqlite3-new $DB <<EOF
SELECT url,
       SUM(num_hits) * 100.0 / SUM(num_hits) OVER () AS percentage,
       SUM(num_hits) OVER ()
FROM traffic
GROUP BY url
ORDER BY percentage DESC;
EOF

}

"$@"
