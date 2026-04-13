#!/bin/bash

(banana-check-repo || true) | (
    err_banana=false
    while read p; do
        file_name="$(echo "$p" | cut -d ":" -f 1)"
        if test "$p" != "Checking delivery files in ." && test "$p" != "No infractions found"; then
            err_banana=true
            echo "::error file=$(echo "$p" | cut -d ":" -f 1),\
        title=$(echo "$p" | cut -d "[" -f 3 | cut -d "]" -f 1) coding style error\
        ::$(echo "$p" | cut -d "(" -f 2 | cut -d ")" -f 1) -$(echo "$p" | cut -d "]" -f 3 | cut -d "(" -f 1 )"
        fi
    done

    if [ "$err_banana" == true ]; then
        echo "::warning ::Exiting due to coding style errors"
        exit 1
    else
        echo "[✅] - No coding styles errors were found by banana"
    fi
)
