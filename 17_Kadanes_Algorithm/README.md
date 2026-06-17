# 📈 Kadane's Algorithm Pattern

## When to Use

Use **Kadane's Algorithm** when you need to find the **maximum or minimum sum of a contiguous subarray** within a one-dimensional numeric array. 

The key insight: A maximum subarray either extends the previous maximum subarray, or starts a new one at the current element.

## Core Idea

```
best_ending = max(current_element, best_ending + current_element)
ans = max(ans, best_ending)
```

- Iterate through the array.
- Maintain the maximum sum ending at the current position.
- If the running sum becomes negative (or less than the current element), it's better to start a new subarray from the current element.

---

## Common Keywords to Look For

| Keyword / Phrase               | Why It Signals Kadane's Algorithm           |
| ------------------------------ | ------------------------------------------ |
| **"maximum subarray"**         | Direct application of Kadane's              |
| **"contiguous sequence"**      | Subarrays are contiguous                    |
| **"largest sum"**              | Optimization over contiguous elements       |

---

## Complexity Cheat Sheet

| Variant               | Time  | Space |
| --------------------- | ----- | ----- |
| Max/Min Subarray      | O(N)  | O(1)  |

---

## Classic Problems in This Pattern

| LC # | Problem Name                        | Difficulty | File |
| ---- | ----------------------------------- | ---------- | ---- |
| 53   | Maximum Subarray                    | 🟡 Medium  | [53_MaximumSubarray.cpp](./53_MaximumSubarray.cpp) |
| 152  | Maximum Product Subarray            | 🟡 Medium  | [152_MaximumProductSubarray.cpp](./152_MaximumProductSubarray.cpp) |
| GFG  | Smallest sum contiguous subarray    | 🟡 Medium  | [SmallestSumSubarray_GFG.cpp](./SmallestSumSubarray_GFG.cpp) |

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 53 | `g++ -std=c++17 -o solution 53_MaximumSubarray.cpp && ./solution` |
| LC 152| `g++ -std=c++17 -o solution 152_MaximumProductSubarray.cpp && ./solution` |
| GFG   | `g++ -std=c++17 -o solution SmallestSumSubarray_GFG.cpp && ./solution` |

<details>
<summary>Expected output for all problems</summary>

**LC 53**
```
[PASS] Test 1 | [-2,1,-3,4,-1,...] -> max sum = 6
[PASS] Test 2 | [1] -> max sum = 1
[PASS] Test 3 | [5,4,-1,7,8] -> max sum = 23
[PASS] Test 4 | [-1] -> max sum = -1
[PASS] Test 5 | [-2,-1] -> max sum = -1
[PASS] Test 6 | [-5,-4,-1,-7,-8] -> max sum = -1

✅  All tests executed.
```
**GFG Smallest sum contiguous subarray**
```
[PASS] Test 1 | [3,-4,2,-3,-1,...] -> min sum = -6
[PASS] Test 2 | [2,6,8,1,4] -> min sum = 1
[PASS] Test 3 | [-2,-3,-4,-1] -> min sum = -10
[PASS] Test 4 | [-1,-2,-3,-4] -> min sum = -10
[PASS] Test 5 | [1] -> min sum = 1
[PASS] Test 6 | [5,4,-1,7,8] -> min sum = -1

✅  All tests executed.
```
**LC 152**
```
[PASS] Test 1 | [2,3,-2,4] -> max product = 6
[PASS] Test 2 | [-2,0,-1] -> max product = 0
[PASS] Test 3 | [-2,3,-4] -> max product = 24
[PASS] Test 4 | [0,2] -> max product = 2
[PASS] Test 5 | [-2] -> max product = -2
[PASS] Test 6 | [-2,-3,7] -> max product = 42

✅  All tests executed.
```
</details>
