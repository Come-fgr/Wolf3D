#!/bin/bash

if [[ ! "$1" || "$1" = "-h" ]]; then
    >&2 echo "check_files: expected format: ./check_files.sh [file1,file2,file3,...] (MUST_BE_EXECUTABLE)"
    >&2 echo "  Returns 1 if not all files exists"
    exit 1
fi

if [ "$1" = "false" ]; then exit 0; fi
IFS=','
read -ra newarr <<< "$1"
err_bins=false
for file in ${newarr[@]}; do
    echo "[❔] - Checking if '$file' binary exists"
    if ! [[ -e $file ]]; then
        echo "::error title=A file is missing: '$file'::Expected to have all these files present: $1"
        err_bins=true
    elif [[ ($2 = "true" && ! -x $file) ]]; then
        echo "::error title=A file isn't an executable: '$file'::Expected to have all these executables present: $1"
        err_bins=true
    else
        echo "[✅] - '$file' was found"
    fi
done
if [ $err_bins = "true" ]; then exit 1; fi
