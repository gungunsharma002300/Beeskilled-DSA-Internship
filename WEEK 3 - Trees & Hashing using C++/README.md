# Beeskilled DSA Internship — Week 3: Trees & Hashing (C++)

Language used: **C++** — all files tested and compiled with `g++ -std=c++11` (no errors).

## Folder Structure

```
WEEK 3 - Trees & Hashing using C++/
├── Assignments/
│   ├── 01_BST_Search.cpp                  -> Build a BST and search for a value
│   ├── 02_Tree_Traversals.cpp             -> Recursive Inorder, Preorder, Postorder
│   ├── 03_HashMap_Using_Arrays.cpp        -> HashMap implemented using arrays
│   └── 04_HashTable_Linear_Probing.cpp    -> Hash table with linear probing (collisions)
├── Mini-project/
│   └── Contact_Directory_BST.cpp          -> Contact Directory (BST based): Insert, Search,
│                                              Delete, alphabetical display via inorder()
└── Practice-Questions/
    ├── 01_Recursion_Practice.cpp          -> Recursive factorial, Fibonacci, array sum
    └── 02_BST_Insert_Display_MinMax.cpp   -> BST insert/display, find min & max
```

## How to Compile & Run

Each `.cpp` file is a standalone program with its own `main()`. Compile and run individually:

```bash
g++ -std=c++11 -o 01_BST_Search Assignments/01_BST_Search.cpp
./01_BST_Search
```

Repeat the same for each file you need to run or show output for.

## Notes

- Every program takes input from the console (`cin`) — run it and type the requested values when prompted.
- `Contact_Directory_BST.cpp` has a menu (Insert / Search / Delete / Display / Exit) — keep entering options until you choose `5` to exit.
- All files have comments explaining the logic, in case you're asked to explain your code.
- Add your name/roll number as a comment at the top of each file if your institute requires it before final submission.
