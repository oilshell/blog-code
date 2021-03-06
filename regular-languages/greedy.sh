#!/bin/bash
#
# Experiment: When is .*? necessary?
#
# Conjecture: almost nowhere in regular languages.  It's a performance
# optimization for backtracking engines.  You can trivially rewrite most
# regexes without it.
#
# By definition .* vs. .*? doesn't affect matching.  It only affects submatch
# extraction.  (e.g. the "recognition problem" vs. the "parse problem")
#
# Usage:
#   ./greedy.sh <function name>

set -o nounset
set -o pipefail
set -o errexit

pygrep() {
  ./pygrep.py "$@"
}

csv() {
  cat <<EOF
foo,bar
spam,eggs
EOF
}

html() {
  cat <<EOF
<div foo="bar>
</div>
EOF
}

quotes() {
  cat <<EOF
foo,bar
"spam","eggs"
EOF
}

quotes-demo() {
  # .* matches inner quotes
  quotes | gawk 'match($0, "\"(.*)\"", a) {
    print "0=" a[0] "\t1=" a[1] "\t2=" a[2]
  }
  '

  # more specific
  quotes | gawk 'match($0, "\"([^\"]+)\"", a) {
    print "0=" a[0] "\t1=" a[1] "\t2=" a[2]
  }
  '

  quotes | pygrep '"(.*)"'
  quotes | pygrep '"(.*?)"'
  quotes | pygrep '"([^"]*)"'
}


demo() {
  csv | gawk 'match($0, "(.*),(.*)", a) { print "0=" a[0] "\t1=" a[1] "\t2=" a[2] }'

  echo ---

  html | gawk 'match($0, "<(.*)>", a) { print "0=" a[0] "\t1=" a[1] }'

  html | ./pygrep.py '<(.*)>'
}

lines() {
  echo spam
  echo eggs
}


RG=~/install/ripgrep-0.10.0-x86_64-unknown-linux-musl/rg

submatch-demo() {
  # note:  POSIX regexes don't have this construct, so we use ripgrep.
  for g in ./pygrep.py $RG; do
    echo $g
    echo ===

    for pat in \
      '(.+)(.+)' \
      '(.+?)(.+?)' \
      '(.+)(.+?)' \
      '(.+?)(.+)'
    do
      # woah ripgrep does multiple matches on a line

      lines | $g $pat -r '[ 1: $1 2: $2 ]'
    done
  done
}

survey() {
  local out=$PWD/survey.txt
  cd ~/git/oilshell/oil
  fgrep '.*?' */*.py | tee $out
}

"$@"
