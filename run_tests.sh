#!/usr/bin/env bash

#  run_tests.sh

#  Copyright (c) 2019 Charles Jekel
#  MIT licensed


status=0

echo "Delete .o files"
rm tests/dtw_distance_class.o tests/dtw_path_class.o tests/dtw_distance_only.o tests/exceptions.o p_norm.o

echo "Delete coverage files"
rm tests/*.gcov tests/*.gcda tests/*.gcno

echo "Compling code"

for file in tests/*.cpp; do
    echo "---------------"
    echo "Compiling $file"
    g++ -std=c++11 "$file" -o "$(basename "$file" .cpp).o" -I include --coverage
    echo "Running $file"
    ./"$(basename "$file" .cpp).o"
    if [ $? -eq 0 ]; then
        echo "File $file passed the tests ! ✔ "
    else
        echo "File $file failed ! ❌ "
        status=1
    fi
    # if [status -eq $?]
done
echo "$status"
if (( $status == "0")) ; then
    exit 0
else
    exit 1
fi
