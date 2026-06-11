# FIFO Page Replacement Simulator

A C++ program that simulates the FIFO page replacement algorithm used in operating systems virtual memory management.

## Overview

This project demonstrates how an operating system handles page replacement when physical memory frames are full. The simulator reads a frame count and a page reference string, then processes each page request using the First-In, First-Out replacement strategy.

When a page is not already loaded in memory, a page fault occurs. If all frames are full, the oldest loaded page is removed and replaced with the new page.

## Concepts Demonstrated

- Operating Systems
- Virtual Memory
- Page Replacement Algorithms
- FIFO Queue Logic
- Page Fault Tracking
- C++ Standard Library
- Input Parsing
- Simulation Design

## Technologies

- C++
- STL Vectors
- STL Queues

## Input Format

The program expects input in the following format:

```text
Frames 3
7 0 1 2 0 3 0 4 2 3 0 3 2
```

The first line specifies the number of memory frames.

The remaining values represent the page reference string.

## Example Run

### Input

```text
Frames 3
7 0 1 2 0 3 0 4 2 3 0 3 2
```

### Output

```text
7 0 1 2 0 3 0 4 2 3 0 3 2
Page replacement using FIFO
time step 0: 7 
time step 1: 7 0 
time step 2: 7 0 1 
time step 3: 0 1 2 
time step 4: 0 1 2 
time step 5: 1 2 3 
time step 6: 2 3 0 
time step 7: 3 0 4 
time step 8: 0 4 2 
time step 9: 4 2 3 
time step 10: 2 3 0 
time step 11: 2 3 0 
time step 12: 2 3 0 
total number of page faults = 10
```

## How It Works

1. Read the number of available frames.
2. Read the page reference string.
3. For each page reference:
   - Check whether the page is already in memory.
   - If it is present, no page fault occurs.
   - If it is not present, increment the page fault count.
   - If memory has space, insert the page.
   - If memory is full, remove the oldest page using FIFO order.
4. Print the frame state at each time step.
5. Output the total number of page faults.

## How to Run

Compile the program:

```bash
g++ fifo_page_replacement.cpp -o fifo
```

Run the program:

```bash
./fifo < input.txt
```

## File Structure

```text
fifo-page-replacement/
├── src/
│   └── fifo_page_replacement.cpp
├── examples/
│   └── input.txt
└── README.md
```

## Author

Kalyani Valath
