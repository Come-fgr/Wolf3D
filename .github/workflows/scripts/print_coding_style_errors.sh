#!/bin/bash

if [[ ! "$1" || "$1" = "-h" ]]; then
    >&2 echo "print_coding_style_errors: expected format: ./print_coding_style_errors.sh [file]"
    exit 1
fi

while read p; do
    file_name="$(echo "$p" | cut -d ":" -f 1)"
    if test "$file_name" != "$p" && test "$file_name" != "make"; then
        echo "::error file=$(echo "$p" | cut -d ":" -f 1),\
line=$(echo "$p" | cut -d ":" -f 2),\
col=$(echo "$p" | cut -d ":" -f 3),\
title=$(echo "$p" | cut -d "[" -f 3 | cut -d "]" -f 1) coding style error\
::$(echo "$p" | cut -d "(" -f 2 | cut -d ")" -f 1) -$(echo "$p" | cut -d "]" -f 3 | cut -d "(" -f 1 )"
    fi
done < $1;

if [ -s "$1" ]; then
    echo "::warning ::Exiting due to coding style errors"
    exit 1
else
    echo "[✅] - No coding styles errors were found by epiclang"
fi