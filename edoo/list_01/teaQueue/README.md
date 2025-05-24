# Tea Queue

## Problem Description

A group of students attending a programming camp line up to get tea from a single teapot. Each student arrives at a specified time and must wait in line. If they cannot reach the teapot before their patience runs out, they leave without tea. Your task is to determine at what second each student gets their tea (if they do).

### Input Format

The first line contains an integer t, the number of test cases.
Each test case starts with an integer n, the number of students.
The next n lines each contain two integers li and ri, representing the second a student arrives and the last second they are willing to wait.

### Output Format
For each test case, print n integers. The i-th integer represents the second when student i gets their tea, or 0 if they leave without it.

### Example

#### Input:

```
2
2
1 3
1 4
3
1 5
1 1
2 3
```

#### Output:
```
1 2
1 0 2
```
