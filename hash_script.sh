#!/bin/bash

# Ensure exactly one argument is provided
if [ "$#" -ne 1 ]; then
        echo "Please provide a single 4-digit number"
        exit 1
fi

input=$1

# Verify that the argument is a 4-digit number
if ! [[ "$input" =~ ^[0-9]{4}$ ]]; then
        echo "Error: Input must consist of exactly 4 digits"
        exit 1
fi

# Compute and display the SHA-256 hash of the input
echo -n "$input" | sha256sum | awk '{print $1}'
