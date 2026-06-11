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

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 167 | `g++ -std=c++17 -o solution 167_TwoSumII_Optimized.cpp && ./solution` |
| LC 26  | `g++ -std=c++17 -o solution 26_RemoveDuplicates.cpp && ./solution` |
| LC 977 | `g++ -std=c++17 -o solution 977_SortedSquares.cpp && ./solution` |
| LC 15  | `g++ -std=c++17 -o solution 15_3Sum.cpp && ./solution` |
| LC 16  | `g++ -std=c++17 -o solution 16_3SumClosest.cpp && ./solution` |
| GFG    | `g++ -std=c++17 -o solution CountTriplets_GFG.cpp && ./solution` |
| LC 75  | `g++ -std=c++17 -o solution 75_SortColors.cpp && ./solution` |

<details>
<summary>Expected output for all problems</summary>

**LC 167**
```
[PASS] Test 1 | [2,7,11,15] target=9      → [1, 2]
[PASS] Test 2 | [2,3,4] target=6          → [1, 3]
[PASS] Test 3 | [-1,0,1,2] target=1       → [1, 4]
✅  All 3 tests passed.
```
**LC 26**
```
[PASS] Test 1 | [1,1,2]               → k=2 | nums=[1,2]
[PASS] Test 2 | [0,0,1,1,1,2,2,3,3,4] → k=5 | nums=[0,1,2,3,4,...]
[PASS] Test 3 | []                    → k=0
[PASS] Test 4 | [1,2,3,4,5]           → k=5
[PASS] Test 5 | [7,7,7,7]             → k=1
✅  All 5 tests passed.
```
**LC 977**
```
[PASS] Test 1 | [-4,-1,0,3,10]  → [0,1,9,16,100]
[PASS] Test 2 | [-7,-3,2,3,11]  → [4,9,9,49,121]
[PASS] Test 3 | [1,2,3]          → [1,4,9]
[PASS] Test 4 | [-3,-2,-1]       → [1,4,9]
[PASS] Test 5 | [0]              → [0]
✅  All 5 tests passed.
```
**LC 15**
```
[PASS] Test 1 | [-1,0,1,2,-1,-4]  → [[-1,-1,2],[-1,0,1]]
[PASS] Test 2 | [0,1,1]            → []
[PASS] Test 3 | [0,0,0]            → [[0,0,0]]
[PASS] Test 4 | [-2,0,0,2,2]       → [[-2,0,2]]
✅  All 4 tests passed.
```
**LC 16**
```
[PASS] Test 1 | [-1,2,1,-4] target=1   → 2
[PASS] Test 2 | [0,0,0] target=1        → 0
[PASS] Test 3 | [1,1,1,0] target=100    → 3
[PASS] Test 4 | [1,2,5,10,11] target=12 → 13
✅  All 4 tests passed.
```
**GFG Count Triplets**
```
[PASS] Test 1 | arr=[5,1,3,4,7], sum=12  → 4
[PASS] Test 2 | arr=[4,2,1], sum=2        → 0
[PASS] Test 3 | arr=[1,2,3], sum=7        → 1
[PASS] Test 4 | arr=[1,2,3,4,5], sum=12  → 9
✅  All 4 tests passed.
```
**LC 75**
```
[PASS] Test 1 | [2,0,2,1,1,0] → [0,0,1,1,2,2]
[PASS] Test 2 | [2,0,1]       → [0,1,2]
[PASS] Test 3 | []            → []
[PASS] Test 4 | [0]           → [0]
[PASS] Test 5 | [0,1,2]       → [0,1,2]
[PASS] Test 6 | [2,2,2]       → [2,2,2]
✅  All 6 tests passed.
```
</details>
