#!/bin/bash

# Allways run this script from project ROOT directory, not from script directory!
HW0_ROOT_DIR="$(pwd)"

CLANG_FORMAT="clang-format"
#SCRIPT_DIR="$(dirname "$0")"
OPTS="-i --style=file:${HW0_ROOT_DIR}/src/scripts/formatter/.clang-format"

if [[ "$1" == "check" ]]; then
    OPTS="${OPTS} --Werror --dry-run"
fi

find "$HW0_ROOT_DIR" -not -path "*build/*" -and \( -name "*.h" -or -name "*.cpp" \) -print0 | \
xargs -0 $CLANG_FORMAT $OPTS

