#!/bin/bash

# Read the input from input.txt
input=$(<input.txt)
enabled=true
sum=0

# Function to extract and multiply numbers
multiply() {
    local x=$1
    local y=$2
    echo $((x * y))
}

# Iterate through the input string
while [[ $input =~ (do\(\)|don\'t\(\)|mul\(([0-9]+),([0-9]+)\)) ]]; do
    match="${BASH_REMATCH[0]}"
    if [[ $match == "do()" ]]; then
        enabled=true
    elif [[ $match == "don't()" ]]; then
        enabled=false
    elif [[ $match =~ mul\(([0-9]+),([0-9]+)\) ]]; then
        if $enabled; then
            x="${BASH_REMATCH[1]}"
            y="${BASH_REMATCH[2]}"
            sum=$((sum + $(multiply $x $y)))
        fi
    fi
    input="${input#*$match}"
done

echo "Sum of enabled multiplications: $sum"
