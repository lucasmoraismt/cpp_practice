# Traversing Tree

## Problem Description

You are given a sequence of numbers that must be inserted into a **Binary Search Tree (BST)** following standard rules: values smaller than the current node go to the **left**, and values greater go to the **right**. After constructing the BST, you must print the values using **pre-order**, **in-order**, and **post-order** traversals.

## Input Format

- The first line contains an integer **n** (0 < n ≤ 100), representing the number of elements.
- The second line contains **n** space-separated integers (**0 < pi ≤ 50000**), which should be inserted into the BST in the given order.

## Output Format

Print three lines:
1. **Pre-order traversal**, starting with `"Pre order :"` followed by the values.
2. **In-order traversal**, starting with `"In order  :"` followed by the values.
3. **Post-order traversal**, starting with `"Post order:"` followed by the values.

## Example

### Input:
```
7
5 3 7 2 4 6 8
```

### Output:
```
Pre order : 5 3 2 4 7 6 8
In order  : 2 3 4 5 6 7 8
Post order: 2 4 3 6 8 7 5
```
