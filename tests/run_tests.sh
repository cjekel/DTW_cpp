#!/usr/bin/env bash

status=0

echo "Delete .o files"
rm dtw_distance_class.o dtw_path_class.o dtw_distance_only.o exceptions.o p_norm.o

echo "Compling code"
# g++ dtw_distance_class.cpp -o dtw_distance_class.o
# g++ dtw_path_class.cpp -o dtw_path_class.o
# g++ dtw_distance_only.cpp -o dtw_distance_only.o
# g++ excpetions.cpp -o excpetions.o

for file in *.cpp; do
    echo "---------------"
    echo "Compiling $file"
    g++ "$file" -o "$(basename "$file" .cpp).o"
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