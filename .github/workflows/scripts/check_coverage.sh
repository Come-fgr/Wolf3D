#!/bin/bash

if [[ ! "$1" || "$1" = "-h" ]]; then
    >&2 echo "check_coverage: expected format: ./check_coverage.sh [MIN_PERCENT]"
    exit 1
fi

make coverage | (
    min_percent="$1"
    while read p; do
        arr=(${p//" "/ })
        percent=$(echo "${arr[3]}")
        percent="${percent//%/}"
        re='\b[0-9]\b'
        if [[ $percent =~ $re ]] ; then
            if [[ ${arr[0]} != 'TOTAL' ]]; then
                if [[ ! $percent -gt "$min_percent" ]] ; then
                    echo "::warning file=${arr[0]},\
    title=Not enought coverage $percent%\
    ::$percent%/$min_percent% - Missing lines: ${arr[4]}"
                else
                    echo "[✅] - ${arr[0]}: file has enought coverage"
                fi
            else
                if [[ ! $percent -gt "$min_percent" ]] ; then
                    echo "::error title=Not enought global coverage::$percent% coverage - expected at least $min_percent"
                    exit 1
                else
                    echo "--------------------------------------"
                    echo "[✅] - Repository has enought coverage: $percent%/$min_percent%"
                    exit 0
                fi
            fi
        fi
    done
)
