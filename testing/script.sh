#!/bin/bash

arr_fixed_n=(10 100 1000 10000 100000 1000000)



for fixed_n in "${arr_fixed_n[@]}"; do
    max_m=$((fixed_n*(fixed_n-1)/2))
    if [ "$max_m" -lt 10001 ]; then
    # Dense graph
        max_m=$(awk -v m="$max_m" 'BEGIN {print (m < 1000000) ? m : 1000000}')
    else
    # Sparse graph
        max_m=$(awk -v m="$max_m" 'BEGIN {print (m < 10000) ? m : 10000}')
    fi
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
