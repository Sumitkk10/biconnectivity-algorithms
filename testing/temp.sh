#!/bin/bash

arr_fixed_n=(100000 1000000)

for fixed_n in "${arr_fixed_n[@]}"; do
    max_m=$((fixed_n*(fixed_n-1)/2))
    max_m=$(awk -v m="$max_m" 'BEGIN {print (m < 1000000) ? m : 1000000}')
    step=$((max_m/20))

    for ((m=n; m<=max_m; m+=step)); do
        echo "Running script with n=$fixed_n and m=$m"
        chmod +x ./script.sh

        string1="output"
        us="_"
        ext=".txt"
        concatenated="$string1$us$((fixed_n))$ext"
        ./script.sh "$fixed_n" "$m" "$concatenated"
    done
done
