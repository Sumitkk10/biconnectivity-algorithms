#!/bin/bash

arr_fixed_n=(10000)



for fixed_n in "${arr_fixed_n[@]}"; do
    max_m=$((fixed_n*(fixed_n-1)/2))
    if [ "$fixed_n" -lt 10001 ]; then
    # Dense graph
        max_m=$(awk -v m="$max_m" 'BEGIN {print (m < 1000000) ? m : 1000000}')
    else
    # Sparse graph
        max_m=$(awk -v m="$max_m" 'BEGIN {print (m < 10000) ? m : 10000}')
    fi
    step=$((max_m/20))
    # print max_m here
    
    # echo "Max m: $max_m $step"
    for ((m=0; m<=max_m; m+=step)); do
        chmod +x ./helper.sh

        string1="output"
        us="_"
        ext=".txt"
        concatenated="$string1$us$((fixed_n))$ext"
        # create a new file if does not exist
        # if [ ! -f $concatenated ]; then
        #     touch $concatenated
        # fi
        ./helper.sh "$fixed_n" "$m" "$concatenated"
    done
done
