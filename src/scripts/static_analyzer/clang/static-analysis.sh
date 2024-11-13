#!/bin/bash

# Allways run this script from project ROOT directory, not from script directory!
HW0_ROOT_DIR="$(pwd)"
CLANG_TIDY="clang-tidy-15"

#https://stackoverflow.com/questions/39455090/clang-tidy-cant-find-my-header-files

OPTS="--config-file=${HW0_ROOT_DIR}/src/scripts/static_analyzer/clang/.clang-tidy"
OPTS="${OPTS} -header-filter=.*"
OPTS="${OPTS} -p=${HW0_ROOT_DIR}/cmake-build-debug/compile_commands.json"

find "$HW0_ROOT_DIR" -not -path "*build/*" -and -not -path "*install/*" -and -not -path "*cmake-build-debug/*" \( -name "*.h" -or -name "*.cpp" \) -print0 | \
xargs -0 $CLANG_TIDY ${OPTS}