# Tree Implementation in C++

This project contains a generic tree implementation in C++ that supports various types of nodes, including `int`, `double`, `string`, and custom types like `Complex`. The implementation includes methods for tree manipulation and traversal, with special support for binary trees and a `myHeap()` method to convert a binary tree to a min-heap. The project also uses the doctest framework for testing.

## Files

- `Complex.hpp`: Header file for the `Complex` class, which represents complex numbers.
- `main.cpp`: A main program demonstrating the usage of the tree implementation.
- `Makefile`: A Makefile for building the project and running tests.
- `Node.hpp`: Header file for the `Node` class template, representing nodes in the tree.
- `Test.cpp`: A file containing tests for the tree implementation using the doctest framework.
- `Tree.hpp`: Header file for the `Tree` class template, representing the tree.

## Classes and Methods

### `Tree` Class

Defined in `Tree.hpp`, the `Tree` class template represents a generic tree. By default, it supports a binary tree structure.

#### Methods

- `Tree()`: Constructor to initialize an empty binary tree.
- `void add_root(const Node<T>& root)`: Adds a root node to the tree.
- `void add_sub_node(Node<T>& parent, Node<T>& child)`: Adds a child node to a specified parent node.
- `void myHeap()`: Converts the binary tree into a min-heap.

## Iterators

The `Tree` class provides iterators for various traversal methods:

### Binary Tree Specific Iterators

The following methods work specifically for binary trees:
 `begin_in_order()`: Returns an iterator to the beginning of the in-order traversal.
- `end_in_order()`: Returns an iterator to the end of the in-order traversal.
- `begin_pre_order()`: Returns an iterator to the beginning of the pre-order traversal.
- `end_pre_order()`: Returns an iterator to the end of the pre-order traversal.
- `begin_post_order()`: Returns an iterator to the beginning of the post-order traversal.
- `end_post_order()`: Returns an iterator to the end of the post-order traversal.

### BFS and DFS Iterators

The `Tree` class supports BFS (Breadth-First Search) and DFS (Depth-First Search) traversal methods:

- `begin_bfs_scan()`: Returns an iterator to the beginning of the BFS traversal.
- `end_bfs_scan()`: Returns an iterator to the end of the BFS traversal.
- `begin_dfs_scan()`: Returns an iterator to the beginning of the DFS traversal.
- `end_dfs_scan()`: Returns an iterator to the end of the DFS traversal.

### Min-Heap Conversion

The `myHeap()` method converts the binary tree into a min-heap.
