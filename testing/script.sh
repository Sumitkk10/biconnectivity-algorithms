#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <n> <m>"
    exit 1
fi

n=$1
m=$2

# Compile the generator and solution
g++ generator.cpp -o generator
g++ ../code/jen-schmidt.cpp -o solution
g++ ../code/tarjan.cpp -o solution1
g++ ../code/tarjan_extended.cpp -o solution2

# Run the generator and store its output in input.txt
./generator $n $m > input.txt

# Run the solution with input.txt and store its output in temp.txt
./solution < input.txt > temp.txt

./solution1 < input.txt > temp1.txt

./solution2 < input.txt > temp2.txt

echo -n "$n $m $(cat temp.txt) $(cat temp1.txt) $(cat temp2.txt)" >> output.txt


# Clean up temp.txt, input.txt, and the compiled executables
rm temp.txt input.txt generator solution solution1 solution2 temp1.txt temp2.txt

echo "Output stored in output.txt"

