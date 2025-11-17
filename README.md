# Data Structures ADT files in C for Semester III Lab

A collection of Abstract Data Type (ADT) implementations in C, created for the third-semester Data Structures lab (UCS3311). This repository provides header files for various common data structures in the syllabus which can be used for learning for exams or for implimentation.  

---

## ADT Specific Notes
+ The header node of the linked lists are empty and hold no value.
+ The `init()` function should be called after initialization of the stack to initialize the top and size values.
+ The `init()` function should be called after initialization of the queue to initialize the front, rear and legth values.
+ New node is malloced internally in `insert()` function in `bstADT.h`.
+ New node is malloced internally in the `createNode()` funtion in `trieADT.h`.
+ Use `graphADT.h` for undirected graph creating and operations like BFS and DFS.
+ Use `shortestPathADT.h` for directed graph creation and finding the shortest path using dijkstra's algorithm.
+ For disjoint set, call the `makeSet(n)` function internally mallocs the structure and return the data structure's pointer.

---
 
## Instructions
This guide will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need a C compiler like `gcc` and `git` installed on your system.

*   **gcc**: To compile the C source files.
*   **git**: To clone the repository from GitHub.

### Clonning and Execution

Follow these steps to clone the repository, compile the test driver, and run the executable:

- Clone the repository open it
```bash
git clone https://github.com/K-Surya/Sem-3-Data-Structures-ADTs.git
cd Sem-3-Data-Structures-ADTs
```

- Create a driver code eg: `testDriver.c`
- Compile and run the code

```bash
gcc testDriver.c -o driver
./driver
```
---

#### Suggestion
If you have any other code or other material which could be added to this repository, feel free to raise a pull request.

---

## Contributors
- Surya K
- Shalon Jovan
