# C++ Data Structures Library

A modular C++ library implementing classical and advanced data structures from scratch.

This project is being built incrementally, with one data structure implemented and explored each day. The goal is not only to practice DSA concepts, but also to understand:

- memory management
- modular software design
- build systems
- hashing
- tree structures
- probabilistic data structures
- systems-level thinking in C++

Because eventually “just solving LeetCode” starts feeling like teaching a goldfish differential equations.

---

# Current Implementations

## Implemented Data Structures

### Trie
Supports:
- word insertion
- exact word search
- prefix checking
- retrieval of all words
- retrieval of words with a given prefix

---

### Bloom Filter
Probabilistic data structure supporting:
- insertion
- membership queries

Features:
- configurable false positive probability
- dynamic sizing
- double hashing
- compact bit storage using `std::vector<bool>`

Properties:
- no false negatives
- possible false positives

---

### Disjoint Set Union (Union-Find)
Supports:
- union operation
- find operation
- connectivity checking

Optimizations:
- path compression
- union by rank

---

### Segment Tree
Supports:
- range sum queries
- point updates

Additional structures:
- min segment tree
- max segment tree

---

# Project Structure

```text
project/
│
├── demos/
│   └── (interactive demo files)
│
├── include/
│   └── _utility.h
│
├── object_files/
│   ├── demos/
│   └── src/
│
├── src/
│   ├── bloom_filter.cpp
│   ├── disjoint_set.cpp
│   ├── segment_tree.cpp
│   ├── trees.cpp
│   └── trie.cpp
│
├── _main.cpp
├── Makefile
└── README.md
```

---

# Build Instructions

## Compile

```bash
make
```

---

## Run

```bash
./main
```

---

## Clean Build Files

```bash
make clean
```

---

# Compiler Requirements

- C++17 or later
- GNU Make
- g++

Tested on:
- Linux
- WSL2

Because Windows native C++ tooling remains one of humanity’s longest-running social experiments.

---

# Makefile Features

The project uses a modular Makefile with:
- automatic object generation
- separate object directory
- scalable multi-folder build structure
- automatic dependency mapping

Generated object files are stored inside:

```text
object_files/
```

to keep the source tree clean.

---

# Design Philosophy

This project focuses on:

- clean modular implementations
- reusable APIs
- separation of interface and implementation
- understanding internal mechanics instead of relying on STL abstractions

The intention is to learn:
- how data structures actually work
- how large C++ projects are organized
- how compilation and linking behave internally

Not just memorizing operations for interviews like a distressed autocomplete engine.

---

# Future Implementations

Planned structures include:

- Fenwick Tree
- AVL Tree
- Red Black Tree
- Heap
- Graph Algorithms
- LRU Cache
- Skip List
- Suffix Trie
- Sparse Table
- Hash Map
- Treap

and whatever other algorithmic rabbit hole appears at 1:37 AM.

---

# Learning Goals

This repository is also being used to explore:

- object-oriented programming
- memory optimization
- hashing techniques
- probabilistic data structures
- recursion-heavy structures
- software engineering practices
- Makefiles and build systems

---

# Author

Built as part of a long-term DSA + Systems Programming learning project in C++.
