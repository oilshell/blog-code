#!/usr/bin/env bash
#
# Usage:
#   ./run.sh <function name>

set -o nounset
set -o pipefail
set -o errexit

download() {
  mkdir -p _deps
  wget --no-clobber --directory _deps \
    https://www.python.org/ftp/python/3.10.0/Python-3.10.0.tar.xz
}

readonly PY_310=_deps/Python-3.10.0/python

stdlib_ast() {
  $PY_310 stdlib_ast.py
}

dataclass_ast() {
  $PY_310 dataclass_ast.py
}

class_ast() {
  $PY_310 class_ast.py
}

typed() {
  # mypy 0.812 doesn't understand the match statement!
  # mypy typed.py
  #
  # As of 11/2021, the latest mypy is 0.910, released June 2021.  So it
  # probably doesn't support Python 3.10 syntax yet.
  $PY_310 typed.py
}

# Change PYTHONPATH to match this for $PY_310
pythonpath() {
  python3 -c 'import sys; print(sys.path)'
}

mypy() {
  # we need to run with Python 3.10 for pattern matching

  PYTHONPATH=~/.local/lib/python3.6/site-packages $PY_310 ~/.local/bin/mypy "$@"
}

# match statement support
# https://mypy-lang.blogspot.com/2022/03/mypy-0940-released.html
install-mypy() {
  pip3 install mypy
}

readonly REPO_ROOT=~/git/oilshell/oil
readonly py_310=$PWD/$PY_310

parse-all() {
  cd $REPO_ROOT
  test/py3_parse.sh all-files | egrep '\.py$' | xargs -- $py_310 test/py3_parse.py
}

parse-one() {
  AST_DUMP=1 $PY_310 $REPO_ROOT/test/py3_parse.py "$@"
}

syntax-error() {
  parse-one syntax_error.py
}

check-all() {
  for p in *.py; do
    if test "$p" = 'syntax_error.py'; then
      continue
    fi
    echo
    echo "=== $p ==="
    echo
    mypy $p
  done
}




"$@"
