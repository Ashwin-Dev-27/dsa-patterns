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
| 76   | Minimum Window Substring               | 🔴 Hard    | [76_MinimumWindowSubstring.cpp](./76_MinimumWindowSubstring.cpp) |

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| GFG Max Sum | `g++ -std=c++17 -o solution MaxSumSubarray_GFG.cpp && ./solution` |
| LC 3   | `g++ -std=c++17 -o solution 3_LongestSubstringWithoutRepeatingCharacters.cpp && ./solution` |
| LC 209 | `g++ -std=c++17 -o solution 209_MinSizeSubarraySum.cpp && ./solution` |
| LC 424 | `g++ -std=c++17 -o solution 424_LongestRepeatingCharacterReplacement.cpp && ./solution` |
| GFG K  | `g++ -std=c++17 -o solution LongestKSubstr_GFG.cpp && ./solution` |
| LC 904 | `g++ -std=c++17 -o solution 904_FruitIntoBaskets.cpp && ./solution` |
| LC 76  | `g++ -std=c++17 -o solution 76_MinimumWindowSubstring.cpp && ./solution` |

<details>
<summary>Expected output for all problems</summary>

**GFG Max Sum Subarray**
```
[PASS] Test 1 | arr=[100,200,300,400], k=2    → 700
[PASS] Test 2 | arr=[1,4,2,10,2,3,1,0,20], k=4 → 24
[PASS] Test 3 | arr=[2,3], k=2                → 5
[PASS] Test 4 | arr=[1,2,3,4,5], k=1          → 5
[PASS] Test 5 | arr=[-1,-2,-3,-4], k=2        → -3
✅  All 5 tests passed.
```
**LC 3**
```
[PASS] Test 1 | s="abcabcbb" → 3
[PASS] Test 2 | s="bbbbb"    → 1
[PASS] Test 3 | s="pwwkew"   → 3
[PASS] Test 4 | s=""         → 0
[PASS] Test 5 | s="au"       → 2
✅  All 5 tests passed.
```
**LC 209**
```
[PASS] Test 1 | nums=[2,3,1,2,4,3], target=7 → 2
[PASS] Test 2 | nums=[1,4,4], target=4       → 1
[PASS] Test 3 | nums=[1,1,1,1,1,1,1,1], target=11 → 0
[PASS] Test 4 | nums=[2,3,1,1,1,1], target=5 → 2
[PASS] Test 5 | nums=[1,1,1], target=3       → 3
✅  All 5 tests passed.
```
**LC 424**
```
[PASS] Test 1 | s="ABAB", k=2    → 4
[PASS] Test 2 | s="AABABBA", k=1 → 4
✅  All tests passed.
```
**GFG Longest K Unique**
```
[PASS] Test 1 | s="aabacbebebe", k=3 → 7
[PASS] Test 2 | s="aaaa", k=2        → -1
[PASS] Test 3 | s="eceba", k=2       → 3
[PASS] Test 4 | s="a", k=1           → 1
[PASS] Test 5 | s="abacbebebe", k=3  → 7
✅  All 5 tests passed.
```
**LC 904**
```
[PASS] Test 1 | fruits=[1,2,1]                   → 3
[PASS] Test 2 | fruits=[0,1,2,2]                 → 3
[PASS] Test 3 | fruits=[1,2,3,2,2]               → 4
[PASS] Test 4 | fruits=[3,3,3,1,2,1,1,2,3,3,4]  → 5
[PASS] Test 5 | fruits=[0]                       → 1
✅  All 5 tests passed.
```
**LC 76**
```
[PASS] Test 1 | s="ADOBECODEBANC", t="ABC"    → "BANC"
[PASS] Test 2 | s="a", t="a"                  → "a"
[PASS] Test 3 | s="a", t="aa"                 → ""
[PASS] Test 4 | s="hello", t="xyz"            → ""
[PASS] Test 5 | s="aab", t="aa"               → "aa"
[PASS] Test 6 | s="cabwefgewcwaefgcf", t="cae" → "cwae"
✅  All 6 tests passed.
```
</details>
