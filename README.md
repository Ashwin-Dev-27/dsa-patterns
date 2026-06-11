# 🧠 DSA — Pattern-Based Problem Repository

![Language](https://img.shields.io/badge/Language-C++-00599C?logo=cplusplus&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![Problems Solved](https://img.shields.io/badge/Problems%20Solved-13-blue)
![Patterns Covered](https://img.shields.io/badge/Patterns%20Covered-2-blueviolet)
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
│   ├── 75_SortColors.cpp
│   ├── 977_SortedSquares.cpp
│   └── CountTriplets_GFG.cpp
├── 03_Sliding_Window/
│   ├── README.md                        ← Pattern cheat sheet
│   ├── 209_MinSizeSubarraySum.cpp
│   ├── 3_LongestSubstringWithoutRepeatingCharacters.cpp
│   ├── 424_LongestRepeatingCharacterReplacement.cpp
│   ├── 76_MinimumWindowSubstring.cpp
│   ├── 904_FruitIntoBaskets.cpp
│   ├── LongestKSubstr_GFG.cpp
│   └── MaxSumSubarray_GFG.cpp
├── .gitignore
└── README.md                            ← You are here
```

Folders are **numbered by pattern** (e.g., `02_Two_Pointers/`).  
Files follow the convention: `<LC#>_<ProblemName>_<Approach>.cpp`

---

## 🗺️ Pattern Index

| # | Pattern | Folder | Problems Logged |
|---|---------|--------|-----------------|
| 02 | Two Pointers | [`02_Two_Pointers/`](./02_Two_Pointers/) | 7 |
| 03 | Sliding Window | [`03_Sliding_Window/`](./03_Sliding_Window/) | 7 |

---

## 📊 Progress Tracker

| Pattern | LC # | Problem Name | Difficulty | Approaches Logged | Status |
|---------|------|--------------|------------|-------------------|--------|
| Two Pointers | 167 | Two Sum II – Input Array Is Sorted | 🟡 Medium | Optimized | ✅ Done |
| Two Pointers | 26  | Remove Duplicates from Sorted Array | 🟢 Easy | Original | ✅ Done |
| Two Pointers | 977 | Squares of a Sorted Array | 🟢 Easy | Split & Merge | ✅ Done |
| Two Pointers | 15  | 3Sum | 🟡 Medium | Fix + Two Pointers | ✅ Done |
| Two Pointers | 16  | 3Sum Closest | 🟡 Medium | Fix + Two Pointers | ✅ Done |
| Two Pointers | GFG | Count Triplets with Given Sum | 🟡 Medium | Fix + Two Pointers | ✅ Done |
| Two Pointers | 75 | Sort Colors | 🟡 Medium | Dutch National Flag | ✅ Done |
| Sliding Window | GFG | Max Sum Subarray of size K | 🟢 Easy | Original | ✅ Done |
| Sliding Window | 3 | Longest Substring Without Repeating Characters | 🟡 Medium | Original | ✅ Done |
| Sliding Window | 209 | Minimum Size Subarray Sum | 🟡 Medium | Original | ✅ Done |
| Sliding Window | 424 | Longest Repeating Character Replacement | 🟡 Medium | Optimized | ✅ Done |
| Sliding Window | GFG | Longest K Unique Characters Substring | 🟡 Medium | Original | ✅ Done |
| Sliding Window | 904 | Fruit Into Baskets | 🟡 Medium | Original | ✅ Done |
| Sliding Window | 76  | Minimum Window Substring | 🔴 Hard | Optimized | ✅ Done |

---

## 🚀 How to Run Any Solution

Each `.cpp` is self-contained with a `main()`, test cases, and assertions — just compile and run:

```bash
g++ -std=c++17 -o solution <path/to/file.cpp> && ./solution
```

**Example**
```bash
g++ -std=c++17 -o solution 03_Sliding_Window/76_MinimumWindowSubstring.cpp && ./solution
```

Or use the helper script (Windows PowerShell):
```powershell
.\run.ps1 03_Sliding_Window/76_MinimumWindowSubstring.cpp
```

> 💡 For per-problem expected output, see the `README.md` inside each pattern folder.

---

## 🏗️ Patterns Roadmap

- [ ] 01 — Arrays & Hashing
- [x] **02 — Two Pointers**
- [x] **03 — Sliding Window**
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
