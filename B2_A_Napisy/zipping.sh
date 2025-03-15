#!/bin/bash

# Check if kod.cpp exists in the current directory
if [ ! -f "kod.cpp" ]; then
    echo "Error: kod.cpp not found in the current directory."
    exit 1
fi

# Delete previous kod.zip if it exists
if [ -f "kod.zip" ]; then
    rm "kod.zip"
    if [ $? -ne 0 ]; then
        echo "Error: Could not delete existing kod.zip."
        exit 1
    fi
fi

# Zip kod.cpp into kod.zip
zip "kod.zip" "kod.cpp"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create kod.zip."
    exit 1
fi

echo "Successfully created kod.zip from kod.cpp."