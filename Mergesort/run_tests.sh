#!/bin/bash

echo "********Mergesort********"
# Compile all C++ files
echo "Compiling..."
g++ *.cpp -o a.out
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi
echo "Compilation successful."

# Initialize file counter
file_count=0

# Run the executable with each input file, skipping generate_input.py
echo "Running tests..."

for f in ../inputs/*; do
    # Skip the Python script
    if [[ "$f" == *"generate_input.py"* ]]; then
        continue
    fi

    echo "Processing file #$((file_count + 1)): $f"
    
    # Measure execution time for each file separately
    { time ./a.out "$f"; } 2>&1

    echo "---------------------------"
    
    # Increment file counter
    ((file_count++))
done

# Display total files processed
echo "Total files processed: $file_count"

# Check if the expected count (26) is reached
if [[ $file_count -eq 26 ]]; then
    echo "✅ All 26 files processed successfully!"
else
    echo "⚠ Warning: Expected 26 files, but processed $file_count."
fi
