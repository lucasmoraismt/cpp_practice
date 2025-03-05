# Beiju Text

## Problem Description

You are typing a long text with a broken keyboard where the "Home" ([) and "End" (]) keys are randomly pressed internally. Your task is to reconstruct the final text as it would appear on the screen.

### Input Format

Each test case consists of a single line containing at least one and at most 100,000 characters, including letters, underscores, and the special characters [ and ].

### Output Format

The reconstructed text after applying all "Home" and "End" key movements.

### Example

#### Input:

```
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
```

#### Output:

```
BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University
```
