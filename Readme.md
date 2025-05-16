[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Shreya Sridharan

## Description
This project implements Prim’s Algorithm to find the (MST) of a connected undirected graph using:
- An adjacency matrix to represent the graph
- A custom-built Min Heap to efficiently extract and update the minimum weight edges


## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | o(log v)        |
| Extract Min          | O(log v)        |
| Decrease Key         | O(log v)        |
| Prim’s MST Overall   | o(v^2)          |

since we're using an adjacency matrix and a custom heap, the overall runtime is O(V^2), which makes sense for small graphs.


## Test Case Description

*Input:*

Vertices: 0, 1, 2, 3, 4

Edges and Weights:
- (0, 1) → 2
- (0, 3) → 6
- (1, 2) → 3
- (1, 3) → 8
- (1, 4) → 5
- (2, 4) → 7
- (3, 4) → 9

*expected output*

- 0 -- 1 (2)
- 1 -- 2 (3)
- 1 -- 4 (5)
- 0 -- 3 (6)

- Total Cost: 16