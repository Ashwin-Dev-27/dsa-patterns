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
| 57   | Insert Interval               | 🟡 Medium  | [57_InsertInterval.cpp](./57_InsertInterval.cpp) |
| 986  | Interval List Intersections   | 🟡 Medium  | [986_IntervalListIntersections.cpp](./986_IntervalListIntersections.cpp) |

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 56  | `g++ -std=c++17 -o solution 56_MergeIntervals.cpp && ./solution` |
| LC 57  | `g++ -std=c++17 -o solution 57_InsertInterval.cpp && ./solution` |
| LC 986 | `g++ -std=c++17 -o solution 986_IntervalListIntersections.cpp && ./solution` |

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

**LC 57**
```
[PASS] Test 1 | new=[2,5] into [[1,3],[2,5],[6,9]] -> [[1,5],[6,9]]
[PASS] Test 2 | new=[4,8] into [[1,2],[3,5],[4,8],[6,7],[8,10],[12,16]] -> [[1,2],[3,10],[12,16]]
[PASS] Test 3 | new=[5,7] into [[5,7]] -> [[5,7]]
[PASS] Test 4 | new=[1,2] into [[1,2],[3,5],[6,9]] -> [[1,2],[3,5],[6,9]]
[PASS] Test 5 | new=[8,10] into [[1,3],[4,6],[8,10]] -> [[1,3],[4,6],[8,10]]
[PASS] Test 6 | new=[0,10] into [[0,10],[1,3],[4,6],[7,9]] -> [[0,10]]
[PASS] Test 7 | new=[5,8] into [[1,5],[5,8]] -> [[1,8]]
[PASS] Test 8 | new=[6,9] into [[1,3],[6,9],[6,9]] -> [[1,3],[6,9]]

✅  All tests executed.
```

**LC 986**
```
[PASS] Test 1 | multiple overlaps
[PASS] Test 2 | first list empty -> no intersections
[PASS] Test 3 | second list empty -> no intersections
[PASS] Test 4 | completely disjoint lists
[PASS] Test 5 | boundary touch at single point
[PASS] Test 6 | first fully contains second
[PASS] Test 7 | identical intervals
[PASS] Test 8 | interleaving intervals

✅  All tests executed.
```
</details>
