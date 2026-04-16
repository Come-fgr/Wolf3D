#!/bin/bash

if [[ ! "$1" || "$1" = "-h" || ! "$2" ]]; then
    >&2 echo "check_allowed_functions: expected format: ./check_allowed_functions.sh [allowed1,allowed2,...] [BINARIES] (check_statics)"
    >&2 echo "  Returns 1 if there is a fordbidden function or a function that should be a static one"
    exit 1
fi

alloweds="$1"
bins="$2"
bins_arr=(${bins//","/ })
throw_error=false
all_defs=$(find ./include -iname "*.h" -type f -exec cat {} +)
for bin in "${bins_arr[@]}"; do
    echo "Checking inside $bin binary"
    functions=$(nm -P $bin -g | awk '$1 !~ /^_/ && $1 != "main" && $1 != "data_start" {print $1}')
    functions=(${functions})
    for fn in "${functions[@]}"; do
        f=$(echo "$fn" | cut -d "@" -f 1)
        is_extern=$(echo "$fn" | cut -d "@" -f 2)
        def=$(echo "$all_defs" | grep "$f(" || true)
        if [[ "$def" = "" && ! $(echo "$alloweds" | grep "$f") ]]; then
            if [[ $is_extern == $f ]]; then
                if [[ $3 = "false" ]]; then
                    echo "::warning title=Function should be static '$f'::$f - Not defined inside a header"
                    continue;
                fi
                echo "::error title=Function should be static '$f'::$f - Not defined inside a header"
                throw_error=true
            elif [[ $alloweds != "ALL" ]]; then
                echo "::error title=Function not allowed '$f'::$f - Not allowed - Allowed functions are $alloweds"
                throw_error=true
            fi
        else
            echo "[✅] - Function $f is authorized or not external"
        fi
    done
done
if [ $throw_error = "true" ]; then exit 1; fi
