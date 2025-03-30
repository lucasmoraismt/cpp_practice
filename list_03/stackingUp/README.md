# Stacking Up

## Problem Description

Stacy has started working at Stacks“R”Us, a company specializing in stack-related products. Her first task is to test the Stackulator 3000, an electronic stack machine that supports three operations:

### 1

Push a positive integer onto the stack.

### d

Duplicate the top element of the stack. (Error if the stack is empty.)

### +

Pop the top two elements, decrement all remaining elements by one (removing any that become zero), and push the sum of the two popped elements onto the stack. (Error if there are fewer than two elements.)

---

Given the final desired stack state, the goal is to generate a sequence of commands that, when executed from an empty stack, produce the expected result.

## Input

- An integer n (1 ≤ n ≤ 1000) representing the number of elements in the final stack.

- A single line with n space-separated positive integers (1 ≤ x ≤ 10⁶), describing the stack from bottom to top.

## Output

- A valid sequence of commands (1, d, +) that, when executed, results in the desired stack state.

- The generated program must not exceed 100,000 characters.

- If multiple solutions exist, any valid one may be printed.

## Examples

### Input 1

```txt
3
1 1 1
```

### Output 1

```txt
1dd
```

### Input 2

```txt
3
1 2 3
```

### Output 2

```txt
11+1+1+1+1+11+1+1+11+1+
```
