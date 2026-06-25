# 🗓️ Merge Intervals Pattern

## When to Use

Use **Merge Intervals** when the problem involves **overlapping ranges** — merging them, inserting into them, finding gaps, or checking conflicts. The key insight is to **sort by start time** first, then make a single linear pass to collapse overlapping intervals greedily.

## Core Idea

```
Sort intervals by start time.
Track current = intervals[0]

For each next interval:
  if current.end >= next.start   →  overlap → extend current.end = max(current.end, next.end)
  else                           →  no overlap → push current, move to next
Push the last current.
```

---

## Common Keywords to Look For

| Keyword / Phrase                    | Why It Signals Merge Intervals                     |
| ----------------------------------- | -------------------------------------------------- |
| **"merge overlapping intervals"**   | Classic merge problem                              |
| **"insert interval"**               | Find insertion point + merge                       |
| **"meeting rooms"**                 | Check if any two intervals overlap                 |
| **"minimum number of platforms"**   | Count simultaneous overlaps                        |
| **"non-overlapping intervals"**     | Greedy removal to eliminate overlaps               |
| **"interval scheduling"**           | Maximize non-overlapping intervals                 |

---

## Complexity Cheat Sheet

| Variant                        | Time       | Space |
| ------------------------------ | ---------- | ----- |
| Merge intervals (sort + scan)  | O(N log N) | O(N)  |
| Check for any overlap          | O(N log N) | O(1)  |
| Min platforms / meeting rooms  | O(N log N) | O(N)  |

---

## Classic Problems in This Pattern

| LC # | Problem Name                  | Difficulty | File |
| ---- | ----------------------------- | ---------- | ---- |
| 56   | Merge Intervals               | 🟡 Medium  | [56_MergeIntervals.cpp](./56_MergeIntervals.cpp) |

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 56 | `g++ -std=c++17 -o solution 56_MergeIntervals.cpp && ./solution` |

<details>
<summary>Expected output for all problems</summary>

**LC 56**
```
[PASS] Test 1 | [[1,3],[2,6],[8,10],[15,18]] -> [[1,6],[8,10],[15,18]]
[PASS] Test 2 | [[1,4],[4,5]] -> [[1,5]]
[PASS] Test 3 | [[1,2],[3,4],[5,6]] -> [[1,2],[3,4],[5,6]]
[PASS] Test 4 | [[5,10]] -> [[5,10]]
[PASS] Test 5 | [[1,10],[2,5],[3,8]] -> [[1,10]]
[PASS] Test 6 | [[15,18],[1,3],[2,6],[8,10]] -> [[1,6],[8,10],[15,18]]
[PASS] Test 7 | [[1,2],[2,3],[3,4]] -> [[1,4]]
[PASS] Test 8 | [[1,5],[6,10]] -> [[1,5],[6,10]]

✅  All tests executed.
```
</details>
