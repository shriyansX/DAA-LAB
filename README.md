# DAA LAB - Design and Analysis of Algorithms Laboratory

This repository contains the laboratory implementations and solutions for the Design and Analysis of Algorithms (DAA) course. The project is organized by days, with each day focusing on different algorithmic concepts and implementations.

## 📁 Project Structure

```
DAA LAB/
├── Day 1/          # Basic array operations and algorithms
├── Day 2/          # Sorting algorithms and GCD implementations
├── Day 3/          # Advanced sorting algorithms with analysis
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

## 🛠️ Technologies Used

- **Language**: C
- **Compilers**: GCC (GNU Compiler Collection)
- **File I/O**: Standard C file operations
- **Data Structures**: Arrays, dynamic memory allocation

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

## 📈 Algorithm Analysis

### Time Complexities
- **Bubble Sort**: O(n²) - Best: O(n), Worst: O(n²)
- **Selection Sort**: O(n²) - Best: O(n²), Worst: O(n²)
- **Quick Sort**: O(n log n) - Best: O(n log n), Worst: O(n²)
- **Merge Sort**: O(n log n) - Best: O(n log n), Worst: O(n log n)

### Space Complexities
- **Bubble Sort**: O(1)
- **Selection Sort**: O(1)
- **Quick Sort**: O(log n) - Average case
- **Merge Sort**: O(n)

## 🎯 Key Learning Outcomes

1. **Algorithm Design**: Understanding of various algorithmic paradigms
2. **Complexity Analysis**: Time and space complexity evaluation
3. **Implementation Skills**: Practical coding in C language
4. **Performance Comparison**: Real-world algorithm performance testing
5. **File Handling**: Input/output operations with files
6. **Error Handling**: Robust program design with validation

## 📝 File Descriptions

### Input Files
- `input.txt`, `input1.txt`: Test data for Day 1 programs
- `inGcd.dat`, `inDec.dat`: Input files for Day 2 programs
- `inAsce.dat`, `inDesc.dat`, `inRand.dat`: Test data for Day 3 programs

### Output Files
- `outGcd.dat`, `outBin.dat`: Output files for Day 2 programs
- `outQuickAsce.dat`, `outMergeAsce.dat`: Sorted output files for Day 3

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
