# 🔍 Sliding Window Pattern

## When to Use

Use **Sliding Window** when the problem involves a **contiguous** subarray, substring, or subsegment of a sequence (array or string) that satisfies a specific condition. Instead of recalculating the condition from scratch for every possible subarray in **O(N²)**, sliding window updates the state incrementally by expanding or shrinking the window, achieving **O(N)** time complexity.

## Core Idea

There are two main types of sliding windows:

### 1. Fixed-Size Window
The window size is constant at `K`.
- Compute the result for the first `K` elements.
- Slide the window one element at a time from left to right.
- To update the window state, add the new element entering on the right and subtract/remove the element leaving on the left.

```
Initial window (size 3): [1,  2,  3,  4,  5]
                         [       ]  (sum = 6)

Slide right:             [1,  2,  3,  4,  5]
                              [       ]  (sum = 6 - 1 + 4 = 9)
```

### 2. Variable-Size (Dynamic) Window
The window size changes dynamically based on constraints.
- Expand the window by moving the `right` pointer to include elements until a certain condition is met/violated.
- Shrink the window by moving the `left` pointer to restore the condition or optimize the result.

---

## Common Keywords to Look For

| Keyword / Phrase                     | Why It Signals Sliding Window           |
| ------------------------------------ | --------------------------------------- |
| **"contiguous subarray / substring"**| Indicates adjacent elements in a range |
| **"maximum / minimum sum of size K"**| Classic fixed-size sliding window       |
| **"longest / shortest subarray"**    | Classic variable-size sliding window    |
| **"at most K distinct characters"**  | Requires tracking window frequencies    |

---

## Complexity Cheat Sheet

| Variant              | Time  | Space |
| -------------------- | ----- | ----- |
| Fixed-size Window    | O(N)  | O(1)  |
| Variable-size Window | O(N)  | O(1) or O(K) (e.g. hashmap) |

---

## Classic Problems in This Pattern

| LC # | Problem Name                          | Difficulty | File |
| ---- | ------------------------------------- | ---------- | ---- |
| GFG  | Max Sum Subarray of size K            | 🟢 Easy    | [MaxSumSubarray_GFG.cpp](./MaxSumSubarray_GFG.cpp) |
| 3    | Longest Substring Without Repeating Characters | 🟡 Medium  | [3_LongestSubstringWithoutRepeatingCharacters.cpp](./3_LongestSubstringWithoutRepeatingCharacters.cpp) |
| 209  | Minimum Size Subarray Sum              | 🟡 Medium  | [209_MinSizeSubarraySum.cpp](./209_MinSizeSubarraySum.cpp) |
| 424  | Longest Repeating Character Replacement| 🟡 Medium  | [424_LongestRepeatingCharacterReplacement.cpp](./424_LongestRepeatingCharacterReplacement.cpp) |
| GFG  | Longest K Unique Characters Substring  | 🟡 Medium  | [LongestKSubstr_GFG.cpp](./LongestKSubstr_GFG.cpp) |
| 904  | Fruit Into Baskets                     | 🟡 Medium  | [904_FruitIntoBaskets.cpp](./904_FruitIntoBaskets.cpp) |

