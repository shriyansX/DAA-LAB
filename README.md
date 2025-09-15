# DAA LAB - Design and Analysis of Algorithms Laboratory

This repository contains the laboratory implementations and solutions for the Design and Analysis of Algorithms (DAA) course. The project is organized by days, with each day focusing on different algorithmic concepts and implementations.

## 📁 Project Structure

```
DAA LAB/
├── Day 1/          # Basic array operations and algorithms
├── Day 2/          # Sorting algorithms and GCD implementations
├── Day 3/          # Advanced sorting algorithms with analysis
├── Day 4/          # Heap Sort implementation and analysis
├── Day 5/          # Huffman coding and Knapsack problem
└── README.md       # This file
```

## 🚀 Algorithms Implemented

### Day 1 - Basic Array Operations
- **Program 1**: Find second smallest and second largest elements in an array
- **Program 2**: Array manipulation and analysis
- **Program 3**: Additional array operations
- **Program 4**: Extended array functionality

### Day 2 - Sorting Algorithms & Mathematical Operations
- **Bubble Sort**: Implementation with random array generation
- **Selection Sort**: Classic selection sort algorithm
- **GCD Calculator**: Greatest Common Divisor implementation
- **Binary/Decimal Converter**: Number system conversions

### Day 3 - Advanced Sorting with Analysis
- **Quick Sort**: Implementation with performance analysis
  - Best case, worst case, and average case analysis
  - Comparison counting
  - Partition analysis
- **Merge Sort**: Divide and conquer sorting algorithm
- **Input Generation**: Tools for generating test data
  - Ascending data
  - Descending data
  - Random data

### Day 4 - Heap Sort Implementation
  - Build max-heap from array
  - Heapify procedure
  - In-place sorting
  - Time complexity analysis

### Day 5 - Huffman Coding & Knapsack Problem
- **Huffman Coding**: Implementation of Huffman encoding algorithm for data compression
  - Construction of Huffman tree
  - Generation of prefix codes
  - File-based input/output for encoding
- **Knapsack Problem**: 0/1 Knapsack dynamic programming solution
  - Optimal selection of items based on weight and value
  - Table-based DP approach
  - Input/output via files

## 🛠️ Technologies Used

- **Language**: C
- **Compilers**: GCC (GNU Compiler Collection)
- **File I/O**: Standard C file operations
- **Data Structures**: Arrays, dynamic memory allocation
- **Trees**: Used in Huffman coding (Day 5)
- **Dynamic Programming Table**: Used in Knapsack problem (Day 5)

## 📋 Prerequisites

To run the programs in this repository, you need:

- C compiler (GCC recommended)
- Basic understanding of C programming
- Terminal or command prompt

## 🚀 How to Compile and Run

### Compilation
```bash
# Navigate to the specific day directory
cd Day 1/

# Compile a C program
gcc -o program_name program_name.c

# Example
gcc -o 1 1.c
```

### Execution
```bash
# Run the compiled program
./program_name

# Example
./1
```

## 📊 Program Features

### Day 1 Programs
- **File-based input**: Programs read data from text files
- **Error handling**: Robust input validation
- **Efficient algorithms**: O(n) time complexity for finding second min/max

### Day 2 Programs
- **Interactive sorting**: Visual demonstration of sorting algorithms
- **Random data generation**: Automatic test data creation
- **Mathematical operations**: GCD and number system conversions

### Day 3 Programs
- **Performance analysis**: Detailed comparison and partition counting
- **Multiple data types**: Ascending, descending, and random data support
- **File I/O**: Comprehensive input/output file handling
- **Menu-driven interface**: User-friendly program selection

### Day 4 Programs

### Day 5 Programs
- **Huffman Coding**: Efficient data compression using prefix codes
  - Builds Huffman tree from input frequencies
  - Generates and displays Huffman codes
  - Reads input and writes encoded output to files
- **Knapsack Problem**: Solves 0/1 knapsack using dynamic programming
  - Finds optimal subset of items for maximum value
  - Table-based DP solution with file input/output
  - Displays selected items and total value


### Time Complexities
- **Bubble Sort**: O(n²) - Best: O(n), Worst: O(n²)
- **Quick Sort**: O(n log n) average, O(n²) worst case
- **Merge Sort**: O(n log n) in all cases
- **Heap Sort**: O(n log n) in all cases
- **Quick Sort**: O(n log n) - Best: O(n log n), Worst: O(n²)
- **Merge Sort**: O(n log n) - Best: O(n log n), Worst: O(n log n)
 - **Huffman Coding**: O(n log n) for building tree and generating codes
 - **Knapsack (0/1)**: O(nW) where n = number of items, W = knapsack capacity

### Space Complexities
- **Bubble Sort**: O(1)
- **Selection Sort**: O(1)
- **Quick Sort**: O(log n) - Average case
- **Merge Sort**: O(n)
 - **Huffman Coding**: O(n) for tree and code storage
 - **Knapsack (0/1)**: O(nW) for DP table

## 🎯 Key Learning Outcomes

1. **Algorithm Design**: Understanding of various algorithmic paradigms
2. **Complexity Analysis**: Time and space complexity evaluation
3. **Implementation Skills**: Practical coding in C language
4. **Performance Comparison**: Real-world algorithm performance testing
5. **File Handling**: Input/output operations with files
6. **Error Handling**: Robust program design with validation
7. **Data Compression**: Learn Huffman coding for efficient encoding
8. **Optimization Techniques**: Apply dynamic programming to solve knapsack

## 📝 File Descriptions

### Input Files
 - `huffman_input.txt`: Input for Huffman coding (Day 5)
 - `knapsack_input.txt`: Input for Knapsack problem (Day 5)

### Output Files
 - `huffman_output.txt`: Encoded output for Huffman coding (Day 5)
 - `knapsack_output.txt`: Output for Knapsack problem (Day 5)

## 🤝 Contributing

This is a laboratory repository for educational purposes. If you find any bugs or have suggestions for improvements, feel free to:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## 📚 References

- Introduction to Algorithms (CLRS)
- Data Structures and Algorithm Analysis in C
- Online algorithm visualization tools

## 📄 License

This project is for educational purposes as part of the DAA laboratory course.

---

**Note**: All programs are tested and verified to work correctly. Make sure to have the required input files in the respective directories before running the programs.
