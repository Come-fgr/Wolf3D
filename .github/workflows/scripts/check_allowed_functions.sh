#!/bin/bash

## Error handling
if [[ ! "$1" || "$1" = "-h" || ! "$2" ]]; then
    >&2 echo "format: ./check_allowed_functions.sh [alloweds,...] [BINARIES] (check_statics)"
    >&2 echo "      Can add LIBC to allowed functions"
    >&2 echo "      Returns 1 if there is a fordbidden function or a function that should be a static one"
    exit 1
fi

## Params
alloweds="$1"
bins="$2"
static_required="$3"
SEPARATOR=","

## Authorized binaries array
alloweds_arr=(${alloweds//$SEPARATOR/ })
bins_arr=(${bins//$SEPARATOR/ })

## All headers files with prototypes
all_defs=$(find ./include -iname "*.h" -type f -exec cat {} +)

## An error occured
throw_error=fals

print_authorized_function() {
    echo "[✅] - Function $1 is authorized or not external"
}

name_match_reg() {
    for allowed in "${alloweds_arr[@]}"; do
        if [[ $1 =~ ^$allowed ]]; then
            echo "true"
            return
        fi
    done
    echo "false"
}

should_be_static() {
    if [[ $(name_match_reg $f) == "true" ]]; then
        print_authorized_function $f
        return
    fi
    if [[ $static_required = "false" ]]; then
        echo "::warning title=Function should be static '$f'::$f - Not defined inside a header"
        return
    fi
    echo "::error title=Function should be static '$f'::$f - Not defined inside a header"
    throw_error=true
}

function_not_found_in_headers() {
    if [[ $in_libc == $f ]]; then
        should_be_static $static_required
    elif [[ ! $alloweds =~ "LIBC" ]]; then
        echo "::error title=Function not allowed '$f'::$f - Not allowed - Allowed functions are $alloweds"
        throw_error=true
    else
        print_authorized_function $f
    fi
}

check_if_function_is_authorized() {
    functions=$(nm -P $bin -g | awk '$1 !~ /^_/ && $1 != "main" && $1 != "data_start" {print $1}')
    functions=(${functions})

    for fn in "${functions[@]}"; do
        f=$(echo "$fn" | cut -d "@" -f 1)
        in_libc=$(echo "$fn" | cut -d "@" -f 2)
        #if [[ ! $in_libc && $f =~ "sf*" ]]; then continue; fi
        def=$(echo "$all_defs" | grep "$f(" || true)
        if [[ "$def" = "" && ! $(echo "$alloweds" | grep "$f") ]]; then
            function_not_found_in_headers
        else
            print_authorized_function $f
        fi
    done
}

for bin in "${bins_arr[@]}"; do
    echo "Checking inside $bin binary"
    check_if_function_is_authorized
done

if [ $throw_error = "true" ]; then exit 1; fi
