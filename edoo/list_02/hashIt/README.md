# Hash It

## Problem Description

You need to implement a simple hash table using linear probing for collision resolution. The hash table has a fixed size of 101 and supports two operations: **INSERT** and **DELETE**. The hash function is given by:

```txt
h(s) = sum((s[i] * (i+1)) for i in range(len(s))) % 101
```

## Input Format

- The first line contains an integer **T** (number of test cases).  
- Each test case consists of an integer **N** (number of operations), followed by **N** operations in the format `"INSERT:key"` or `"DELETE:key"`.

## Output Format

For each test case:

- Print all stored keys in the format `"index:key"`, where `index` is the position in the hash table.

## Example

### Input

```txt
1
4
INSERT:hello
INSERT:world
DELETE:hello
INSERT:code
```

### Output

```txt
1:world
19:code
```
