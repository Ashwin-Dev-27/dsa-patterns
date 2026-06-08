# 🔀 Two Pointers Pattern

## When to Use

Use **Two Pointers** when the input is **sorted** (or has an exploitable order) and you
need to find a pair, triplet, or subarray satisfying a condition. Instead of checking
every pair in **O(N²)**, two pointers converge toward the answer in **O(N)**.

## Core Idea

Place one pointer at the **start** (`i`) and one at the **end** (`j`).
Evaluate the condition and move the appropriate pointer inward each step:

```
Sorted array:  [1,  2,  3,  5,  8, 11, 15]
                ^                        ^
                i (left)                 j (right)

  sum < target  →  i++   (need a bigger number)
  sum > target  →  j--   (need a smaller number)
  sum == target →  found!
```

Every move eliminates an entire row or column of the implicit pair matrix — that's
why O(N²) collapses to O(N).

---

## Common Keywords to Look For

| Keyword / Phrase                     | Why It Signals Two Pointers            |
| ------------------------------------ | -------------------------------------- |
| **"sorted array"**                   | Enables directional pointer movement   |
| **"pair that sums to target"**       | Classic opposite-end two-sum pattern   |
| **"in-place"**                       | Avoid extra space → pointer swaps      |
| **"remove duplicates"**              | Slow/fast pointer on sorted data       |
| **"container with most water"**      | Shrink from both ends greedily         |
| **"3Sum / 4Sum"**                    | Fix outer pointer, two-sum the rest    |
| **"valid palindrome"**               | Compare characters from both ends      |
| **"merge two sorted arrays"**        | One pointer per array                  |
| **"minimum window / sliding window"**| Expand right pointer, shrink left      |

---

## Complexity Cheat Sheet

| Variant              | Time  | Space |
| -------------------- | ----- | ----- |
| Opposite-end search  | O(N)  | O(1)  |
| Slow & fast pointer  | O(N)  | O(1)  |
| Sliding window       | O(N)  | O(1)  |

---

## Classic Problems in This Pattern

| LC # | Problem Name                          | Difficulty | File |
| ---- | ------------------------------------- | ---------- | ---- |
| 167  | Two Sum II – Input Array Is Sorted    | 🟡 Medium  | [167_TwoSumII_Optimized.cpp](./167_TwoSumII_Optimized.cpp) |
| 15   | 3Sum                                  | 🟡 Medium  | [15_3Sum.cpp](./15_3Sum.cpp) |
| 16   | 3Sum Closest                          | 🟡 Medium  | [16_3SumClosest.cpp](./16_3SumClosest.cpp) |
| 11   | Container With Most Water             | 🟡 Medium  | — |
| 26   | Remove Duplicates from Sorted Array   | 🟢 Easy    | [26_RemoveDuplicates.cpp](./26_RemoveDuplicates.cpp) |
| 75   | Sort Colors                           | 🟡 Medium  | [75_SortColors.cpp](./75_SortColors.cpp) |
| 977  | Squares of a Sorted Array             | 🟢 Easy    | [977_SortedSquares.cpp](./977_SortedSquares.cpp) |
| 125  | Valid Palindrome                      | 🟢 Easy    | — |
| 42   | Trapping Rain Water                   | 🔴 Hard    | — |
| GFG  | Count Triplets with Given Sum         | 🟡 Medium  | [CountTriplets_GFG.cpp](./CountTriplets_GFG.cpp) |
