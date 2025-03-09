# Sorting Algorithms - Execution Guide
This document provides instructions on how to manually execute sorting algorithms or use an automated script for batch execution.

## Manual Execution
You can manually compile and execute any sorting algorithm by following these steps:

### 1. Navigate to the Sorting Algorithm Folder
Move into the directory of the sorting algorithm you want to test.
For example, to run Heapsort:

```sh
    cd Heapsort
```

### 2. Compile the C++ Code
Use g++ to compile all .cpp files in the folder:

```sh
    g++ *.cpp -o a.out
```

### 3. Execute the Program with an Input File
Replace `*` with the specific input file name located in the `./inputs/` folder.

```sh
    ./a.out ./inputs/*
```
Example:
```sh
    ./a.out ./inputs/input.100000.1
```

### 4. Measure Execution Time
To measure the execution time of a specific input file, use the time command.
Replace `*` with the specific input file name located in the `./inputs/` folder.
```sh
    time for f in ./inputs/*; do echo $f; ./a.out $f; done
```
Example:
```sh
    time for f in ./inputs/input.100000.1; do echo $f; ./a.out $f; done
```


#############################################################################################################




## Automated Execution (Recommended)
Each sorting algorithm folder contains an automation script called `run_tests.sh`, which allows you to efficiently run tests on multiple input files.



### 1. Navigate to the Sorting Algorithm Folder
Example:

```sh
    cd Heapsort
```
### 2. Grant Execution Permission to the Script
Before running the script, ensure it has the correct execution permissions:

```sh
chmod +x run_tests.sh
```
### 3. Run the Script
Execute the script to automatically run the sorting algorithm on multiple input files:

```sh
    ./run_tests.sh
```

### 4. Expected Behavior
- The script compiles the C++ program.
- It runs the program for all available input files in the  `./inputs/` directory.
- It displays execution time for each input file.
- It provides a summary of the total number of files processed.

# Additional Notes
- Ensure that all input files are stored in the ./inputs/ directory.
- The script automatically skips non-input files (e.g., generate_input.py).
- If an error occurs during compilation, execution will be halted.











