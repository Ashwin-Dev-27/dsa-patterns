# 🧠 DSA — Pattern-Based Problem Repository

![Language](https://img.shields.io/badge/Language-C++-00599C?logo=cplusplus&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![Problems Solved](https://img.shields.io/badge/Problems%20Solved-5-blue)
![Patterns Covered](https://img.shields.io/badge/Patterns%20Covered-1-blueviolet)
![License](https://img.shields.io/badge/License-MIT-green)

A structured, pattern-first collection of DSA problems — built for **deep understanding**,
clean **interview revision**, and a professional **portfolio**.

Every solution is:
- ✅ **Locally runnable** — `main()` with test cases and assertions
- ✅ **Fully documented** — approach, complexity, and evolution notes
- ✅ **Pattern-organized** — grouped by algorithmic technique, not just problem number

---

## 📂 Repository Structure

```
dsa/
├── 02_Two_Pointers/
│   ├── README.md                        ← Pattern cheat sheet
│   ├── 167_TwoSumII_Optimized.cpp
│   ├── 15_3Sum.cpp
│   ├── 16_3SumClosest.cpp
│   ├── 26_RemoveDuplicates.cpp
│   └── 977_SortedSquares.cpp
├── .gitignore
└── README.md                            ← You are here
```

Folders are **numbered by pattern** (e.g., `02_Two_Pointers/`).  
Files follow the convention: `<LC#>_<ProblemName>_<Approach>.cpp`

---

## 🗺️ Pattern Index

| # | Pattern | Folder | Problems Logged |
|---|---------|--------|-----------------|
| 02 | Two Pointers | [`02_Two_Pointers/`](./02_Two_Pointers/) | 5 |

---

## 📊 Progress Tracker

| Pattern | LC # | Problem Name | Difficulty | Approaches Logged | Status |
|---------|------|--------------|------------|-------------------|--------|
| Two Pointers | 167 | Two Sum II – Input Array Is Sorted | 🟡 Medium | Optimized | ✅ Done |
| Two Pointers | 26  | Remove Duplicates from Sorted Array | 🟢 Easy | Original | ✅ Done |
| Two Pointers | 977 | Squares of a Sorted Array | 🟢 Easy | Split & Merge | ✅ Done |
| Two Pointers | 15  | 3Sum | 🟡 Medium | Fix + Two Pointers | ✅ Done |
| Two Pointers | 16  | 3Sum Closest | 🟡 Medium | Fix + Two Pointers | ✅ Done |

---

## 🚀 How to Run Any Solution

Each `.cpp` is self-contained — just compile and run:

**LC 167 – Two Sum II**
```bash
g++ -std=c++17 -o solution 02_Two_Pointers/167_TwoSumII_Optimized.cpp && ./solution
```
```
[PASS] Test 1 | [2,7,11,15] target=9      → [1, 2]
[PASS] Test 2 | [2,3,4] target=6          → [1, 3]
[PASS] Test 3 | [-1,0,1,2] target=1       → [1, 4]

✅  All 3 tests passed.
```

**LC 26 – Remove Duplicates from Sorted Array**
```bash
g++ -std=c++17 -o solution 02_Two_Pointers/26_RemoveDuplicates.cpp && ./solution
```
```
[PASS] Test 1 | [1,1,2]               → k=2 | nums=[1,2]
[PASS] Test 2 | [0,0,1,1,1,2,2,3,3,4] → k=5 | nums=[0,1,2,3,4,...]
[PASS] Test 3 | []                    → k=0
[PASS] Test 4 | [1,2,3,4,5]           → k=5
[PASS] Test 5 | [7,7,7,7]             → k=1

✅  All 5 tests passed.
```

**LC 977 – Squares of a Sorted Array**
```bash
g++ -std=c++17 -o solution 02_Two_Pointers/977_SortedSquares.cpp && ./solution
```
```
[PASS] Test 1 | [-4,-1,0,3,10]  → [0,1,9,16,100]
[PASS] Test 2 | [-7,-3,2,3,11]  → [4,9,9,49,121]
[PASS] Test 3 | [1,2,3]          → [1,4,9]
[PASS] Test 4 | [-3,-2,-1]       → [1,4,9]
[PASS] Test 5 | [0]              → [0]

✅  All 5 tests passed.
```

**LC 15 – 3Sum**
```bash
g++ -std=c++17 -o solution 02_Two_Pointers/15_3Sum.cpp && ./solution
```
```
[PASS] Test 1 | [-1,0,1,2,-1,-4]  → [[-1,-1,2],[-1,0,1]]
[PASS] Test 2 | [0,1,1]            → []
[PASS] Test 3 | [0,0,0]            → [[0,0,0]]
[PASS] Test 4 | [-2,0,0,2,2]       → [[-2,0,2]]

✅  All 4 tests passed.
```

**LC 16 – 3Sum Closest**
```bash
g++ -std=c++17 -o solution 02_Two_Pointers/16_3SumClosest.cpp && ./solution
```
```
[PASS] Test 1 | [-1,2,1,-4] target=1   → 2
[PASS] Test 2 | [0,0,0] target=1        → 0
[PASS] Test 3 | [1,1,1,0] target=100    → 3
[PASS] Test 4 | [1,2,5,10,11] target=12 → 13

✅  All 4 tests passed.
```

---

## 🏗️ Patterns Roadmap

- [ ] 01 — Arrays & Hashing
- [x] **02 — Two Pointers**
- [ ] 03 — Sliding Window
- [ ] 04 — Stack
- [ ] 05 — Binary Search
- [ ] 06 — Linked List
- [ ] 07 — Trees
- [ ] 08 — Tries
- [ ] 09 — Heap / Priority Queue
- [ ] 10 — Backtracking
- [ ] 11 — Graphs
- [ ] 12 — Dynamic Programming
- [ ] 13 — Greedy
- [ ] 14 — Intervals
- [ ] 15 — Math & Geometry
- [ ] 16 — Bit Manipulation

---

## 📝 File Naming Convention

| Item | Convention | Example |
|------|-----------|---------|
| Folder | `<NN>_<PatternName>/` | `02_Two_Pointers/` |
| Solution | `<LC#>_<Name>_BruteForce.cpp` | `167_TwoSumII_BruteForce.cpp` |
| Solution | `<LC#>_<Name>_Optimized.cpp` | `167_TwoSumII_Optimized.cpp` |
| Pattern doc | `README.md` inside each folder | `02_Two_Pointers/README.md` |

---

<p align="center">
  <i>Built for learning. Structured for interviews. Maintained with discipline.</i>
</p>
