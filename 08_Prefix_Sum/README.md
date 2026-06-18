# ➕ Prefix Sum Pattern

## When to Use

Use **Prefix Sum** when you need to answer **range sum queries** or find **equilibrium points** (pivot indices) in an array. The key insight is precomputing cumulative sums so that any subarray sum can be computed in O(1) time.

## Core Idea

```
prefix[i] = sum of nums[0..i-1]   (exclusive)
range sum [l..r] = prefix[r+1] - prefix[l]
```

For pivot index:  
If `leftSum == totalSum - nums[i] - leftSum`, then `i` is the pivot.

---

## Common Keywords to Look For

| Keyword / Phrase                 | Why It Signals Prefix Sum                |
| -------------------------------- | ---------------------------------------- |
| **"pivot index"**                | Equilibrium point: left sum == right sum |
| **"range sum query"**            | Multiple subarray sum queries            |
| **"contiguous subarray sum"**    | Cumulative sum check                     |

---

## Complexity Cheat Sheet

| Variant               | Time  | Space |
| --------------------- | ----- | ----- |
| Basic Prefix Sum      | O(N)  | O(N)  |
| Optimized (running)   | O(N)  | O(1)  |

---

## Classic Problems in This Pattern

| LC # | Problem Name                       | Difficulty | File |
| ---- | ---------------------------------- | ---------- | ---- |
| 724  | Find Pivot Index                   | 🟢 Easy    | [724_FindPivotIndex.cpp](./724_FindPivotIndex.cpp) |

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 724 | `g++ -std=c++17 -o solution 724_FindPivotIndex.cpp && ./solution` |

<details>
<summary>Expected output for all problems</summary>

**LC 724**
```
[PASS] Test 1 | [1,7,3,6,5,6] -> pivot = 3
[PASS] Test 2 | [1,2,3] -> pivot = -1
[PASS] Test 3 | [2,1,-1] -> pivot = 0
[PASS] Test 4 | [0,0,0,0] -> pivot = 0
[PASS] Test 5 | [1] -> pivot = 0
[PASS] Test 6 | [] -> pivot = -1
[PASS] Test 7 | [-1,-1,-1,...] -> pivot = 2
[PASS] Test 8 | [-7,1,5,2,-4,...] -> pivot = 3

✅  All tests executed.
```
</details>
