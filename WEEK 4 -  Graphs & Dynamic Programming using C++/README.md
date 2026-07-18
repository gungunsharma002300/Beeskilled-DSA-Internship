# Beeskilled DSA Internship — Week 4: Graphs & Dynamic Programming (C++)

Language used: **C++** — all files tested and compiled with `g++ -std=c++11` (no errors).

## Folder Structure

```
WEEK 4 – Graphs & Dynamic Programming using C++/
├── Assignments/
│   ├── 01_BFS_DFS.cpp                    -> BFS & DFS using adjacency list
│   ├── 02_Dijkstra_Shortest_Path.cpp     -> Shortest path distances (Dijkstra)
│   ├── 03_Fibonacci_Memo_Tabulation.cpp  -> Fibonacci: Memoization + Tabulation
│   └── 04_Knapsack_01.cpp                -> 0/1 Knapsack (bottom-up tabulation)
├── Mini-project/
│   └── City_Path_Finder.cpp              -> Cities as graph nodes; shortest route
│                                             between two named cities (Dijkstra +
│                                             path reconstruction)
└── Practice-Questions/
    ├── 01_Graph_DFS_BFS_Matrix.cpp       -> Same as Assignment 1, but using an
    │                                         Adjacency Matrix representation
    ├── 02_Dijkstra_With_Path.cpp         -> Dijkstra + prints the actual shortest
    │                                         path (not just the distance)
    ├── 03_Knapsack_Memoization.cpp       -> Same Knapsack problem, solved with
    │                                         top-down recursion + memoization
    ├── 04_Longest_Common_Subsequence.cpp -> LCS length + the actual subsequence
    └── 05_Graph_Traversal_Visualizer.cpp -> Visualizes BFS level-by-level and
                                                DFS depth-by-depth step by step
```

## How to Compile & Run

Each `.cpp` file is standalone with its own `main()`. Compile and run individually:

```bash
g++ -std=c++11 -o 01_BFS_DFS Assignments/01_BFS_DFS.cpp
./01_BFS_DFS
```

Repeat for each file.

### Sample input format (for graph-based programs)
When a program asks for edges, enter them as `u v` (and `u v weight` for Dijkstra),
using 0-indexed vertex numbers. Example for 5 vertices, 5 edges:
```
5
5
0 1
0 2
1 3
2 4
3 4
0
```

### City Path Finder (Mini Project)
Runs as a menu: choose option `1` to add roads between cities (by name), option `2`
to find the shortest route between two cities, and `3` to exit.

## Notes

- All files include comments explaining the logic — useful if asked to explain your code.
- `03_Knapsack_Memoization.cpp` and `02_Dijkstra_With_Path.cpp` are intentionally
  different implementations from their Assignments counterparts (memoization vs.
  tabulation, and path-reconstruction vs. distances-only) so the practice set adds
  real value instead of duplicating the assignment code.
- Add your name/roll number as a comment at the top of each file if your institute
  requires it before final submission.
