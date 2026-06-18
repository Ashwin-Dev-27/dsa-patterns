# ➕ Prefix Sum Pattern

## When to Use

Use **Prefix Sum** when you need to answer **range sum queries**, find **equilibrium points**, or **count subarrays** with a target sum. The key insight is precomputing cumulative sums so that any subarray sum can be computed in O(1) time — and pairing it with a hash map enables counting exact-sum subarrays in O(N).

## Core Idea

```
prefix[i] = sum of nums[0..i-1]   (exclusive)
range sum [l..r] = prefix[r+1] - prefix[l]
```

For pivot index:  
If `leftSum == totalSum - nums[i] - leftSum`, then `i` is the pivot.

---

## Common Keywords to Look For

| Keyword / Phrase                 | Why It Signals Prefix Sum                         |
| -------------------------------- | ------------------------------------------------- |
| **"pivot index"**                | Equilibrium point: left sum == right sum          |
| **"range sum query"**            | Multiple subarray sum queries                     |
| **"contiguous subarray sum"**    | Cumulative sum check                              |
| **"number of subarrays = k"**    | Prefix sum + hash map to count exact-sum subarrays |
| **"equal number of 0s and 1s"**  | Treat 0 as -1 and 1 as 1, find subarray sum = 0    |

---

## Complexity Cheat Sheet

| Variant                       | Time  | Space |
| ----------------------------- | ----- | ----- |
| Basic Prefix Sum              | O(N)  | O(N)  |
| Optimized (running)           | O(N)  | O(1)  |
| Prefix Sum + Hash Map (count) | O(N)  | O(N)  |

---

## Classic Problems in This Pattern

| LC # | Problem Name                       | Difficulty | File |
| ---- | ---------------------------------- | ---------- | ---- |
| 525  | Contiguous Array                   | 🟡 Medium  | [525_ContiguousArray.cpp](./525_ContiguousArray.cpp) |
| 560  | Subarray Sum Equals K              | 🟡 Medium  | [560_SubarraySumEqualsK.cpp](./560_SubarraySumEqualsK.cpp) |
| 724  | Find Pivot Index                   | 🟢 Easy    | [724_FindPivotIndex.cpp](./724_FindPivotIndex.cpp) |
| 974  | Subarray Sums Divisible by K       | 🟡 Medium  | [974_SubarraysDivisibleByK.cpp](./974_SubarraysDivisibleByK.cpp) |

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 525 | `g++ -std=c++17 -o solution 525_ContiguousArray.cpp && ./solution` |
| LC 560 | `g++ -std=c++17 -o solution 560_SubarraySumEqualsK.cpp && ./solution` |
| LC 724 | `g++ -std=c++17 -o solution 724_FindPivotIndex.cpp && ./solution` |
| LC 974 | `g++ -std=c++17 -o solution 974_SubarraysDivisibleByK.cpp && ./solution` |

<details>
<summary>Expected output for all problems</summary>

**LC 525**
```
[PASS] Test 1 | [0,1] -> max length = 2
[PASS] Test 2 | [0,1,0] -> max length = 2
[PASS] Test 3 | [0,0,0,1,1,...] -> max length = 6
[PASS] Test 4 | [0,0,1,0,0,...] -> max length = 6
[PASS] Test 5 | [0,0,0] -> max length = 0
[PASS] Test 6 | [1,1,1] -> max length = 0
[PASS] Test 7 | [0,1,1,0,1,...] -> max length = 4
[PASS] Test 8 | [1] -> max length = 0

✅  All tests executed.
```

**LC 560**
```
[PASS] Test 1 | k=2 | [1,1,1] -> count = 2
[PASS] Test 2 | k=3 | [1,2,3] -> count = 2
[PASS] Test 3 | k=1 | [1] -> count = 1
[PASS] Test 4 | k=0 | [-1,-1,1] -> count = 1
[PASS] Test 5 | k=7 | [3,4,7,2,-3,...] -> count = 4
[PASS] Test 6 | k=0 | [1] -> count = 0
[PASS] Test 7 | k=0 | [0,0,0,0] -> count = 10
[PASS] Test 8 | k=4 | [-1,2,3,-1,...] -> count = 3

✅  All tests executed.
```

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

**LC 974**
```
[PASS] Test 1 | k=5 | [4,5,0,-2,-3,...] -> count = 7
[PASS] Test 2 | k=9 | [5] -> count = 0
[PASS] Test 3 | k=5 | [5] -> count = 1
[PASS] Test 4 | k=2 | [0,0,0] -> count = 6
[PASS] Test 5 | k=2 | [-1,2,9] -> count = 2
[PASS] Test 6 | k=3 | [7,3,-3] -> count = 3
[PASS] Test 7 | k=2 | [2,2,2,2] -> count = 10
[PASS] Test 8 | k=5 | [1,2,3,4,5] -> count = 4

✅  All tests executed.
```
</details>
