#!/bin/bash

if [[ ! "$1" || "$1" = "-h" ]]; then
    >&2 echo "check_repo_size: expected format: ./check_repo_size.sh [MAX_SIZE]"
    >&2 echo "check_repo_size: Max size must be in bytes"
    exit 1
fi

size=$(du -s | awk '{print $1}')

if [ "$size" -gt "$1" ]; then
    echo "::error title=Repository too large::Current size is $size and max is $1"
    exit 1
fi
echo "[✅] - Repository size is below the limit: $size/$1"
