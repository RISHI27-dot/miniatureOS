#!/bin/sh

echo "Formatting all the .c and .h files."

find . -name "*.c" -o -name "*.h" | xargs clang-format -i

echo "Done"
