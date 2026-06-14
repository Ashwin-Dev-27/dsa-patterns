# 📓 DSA Session Log
> **Repo:** [dsa-patterns](https://github.com/Ashwin-Dev-27/dsa-patterns) | `c:\Users\Ashwin kumar\Desktop\dsa`  
> **Language:** C++ | **Pattern-first structure**  
> Last updated: 2026-06-15 (Session 14)

---

## ⚙️ Repo Conventions (Don't Change Without Asking)

| Item | Convention | Example |
|------|-----------|---------|
| **Folder** | `<NN>_<PatternName>/` | `02_Two_Pointers/` |
| **Solution file** | `<LC#>_<Name>_<Approach>.cpp` | `167_TwoSumII_Optimized.cpp` |
| **Plain solve** | `<LC#>_<Name>.cpp` | `26_RemoveDuplicates.cpp` |
| **Pattern doc** | `README.md` inside each folder | `02_Two_Pointers/README.md` |
| **Git shell** | PowerShell — use `;` not `&&` | `git add .; git commit ...; git push` |

---

## 📁 Current Repo Structure

```
dsa/
├── 02_Two_Pointers/
│   ├── README.md                    ← Pattern cheat sheet
│   ├── 15_3Sum.cpp
│   ├── 167_TwoSumII_Optimized.cpp
│   ├── 16_3SumClosest.cpp
│   ├── 26_RemoveDuplicates.cpp
│   ├── 75_SortColors.cpp
│   ├── 977_SortedSquares.cpp
│   └── CountTriplets_GFG.cpp
├── 03_Sliding_Window/
│   ├── README.md                    ← Pattern cheat sheet
│   ├── MaxSumSubarray_GFG.cpp
│   ├── 209_MinSizeSubarraySum.cpp
│   ├── 3_LongestSubstringWithoutRepeatingCharacters.cpp
│   ├── 424_LongestRepeatingCharacterReplacement.cpp
│   ├── 76_MinimumWindowSubstring.cpp
│   ├── 904_FruitIntoBaskets.cpp
│   └── LongestKSubstr_GFG.cpp
├── 04_Fast_Slow_Pointers/
│   ├── README.md                    ← Pattern cheat sheet
│   └── 141_LinkedListCycle.cpp
├── .gitignore
├── dsa_session_log.md
├── run.ps1
└── README.md
```

---

## ✅ Problems Logged

| # | LC # | Problem Name | Pattern | Difficulty | File | Approach | Commit |
|---|------|--------------|---------|------------|------|----------|--------|
| 1 | 167 | Two Sum II – Input Array Is Sorted | Two Pointers | 🟡 Medium | `167_TwoSumII_Optimized.cpp` | Opposite-end convergence | `3f453fb` |
| 2 | 26  | Remove Duplicates from Sorted Array | Two Pointers | 🟢 Easy | `26_RemoveDuplicates.cpp` | Slow & fast pointer | `08d6efb` |
| 3 | 977 | Squares of a Sorted Array | Two Pointers | 🟢 Easy | `977_SortedSquares.cpp` | Split & Merge | `bdf5b18` |
| 4 | 15  | 3Sum | Two Pointers | 🟡 Medium | `15_3Sum.cpp` | Fix + Two Pointers | `abaf206` |
| 5 | 16  | 3Sum Closest | Two Pointers | 🟡 Medium | `16_3SumClosest.cpp` | Fix + Two Pointers | `3de7ff4` |
| 6 | GFG | Count Triplets with Given Sum | Two Pointers | 🟡 Medium | `CountTriplets_GFG.cpp` | Fix + Two Pointers | `36a6432` |
| 7 | 75  | Sort Colors | Two Pointers | 🟡 Medium | `75_SortColors.cpp` | Dutch National Flag | `bffb980` |
| 8 | GFG | Max Sum Subarray of size K | Sliding Window | 🟢 Easy | `MaxSumSubarray_GFG.cpp` | Fixed window | `ee215c5` |
| 9 | 209 | Minimum Size Subarray Sum | Sliding Window | 🟡 Medium | `209_MinSizeSubarraySum.cpp` | Variable window | `7399a5a` |
| 10 | GFG | Longest K Unique Characters Substring | Sliding Window | 🟡 Medium | `LongestKSubstr_GFG.cpp` | Variable window + map | `c6c001f` |
| 11 | 904 | Fruit Into Baskets | Sliding Window | 🟡 Medium | `904_FruitIntoBaskets.cpp` | Variable window + map | `34638f7` |
| 12 | 3   | Longest Substring Without Repeating Characters | Sliding Window | 🟡 Medium | `3_LongestSubstringWithoutRepeatingCharacters.cpp` | Variable window + set | `e537c0f` |
| 13 | 424 | Longest Repeating Character Replacement | Sliding Window | 🟡 Medium | `424_LongestRepeatingCharacterReplacement.cpp` | Variable window + freq | `88accec` |
| 14 | 76  | Minimum Window Substring | Sliding Window | 🔴 Hard | `76_MinimumWindowSubstring.cpp` | Variable window + two maps | `f37bbce` |
| 15 | 141 | Linked List Cycle | Fast & Slow Pointers | 🟢 Easy | `141_LinkedListCycle.cpp` | Floyd's Cycle Detection | `8e13867` |
| 16 | 142 | Linked List Cycle II | Fast & Slow Pointers | 🟡 Medium | `142_LinkedListCycleII.cpp` | Floyd's Phase 2 (find start) | `TBD` |

---

## 📝 Change Log

### Session 1 — 2026-06-06
**By:** Antigravity  
**What was done:**
- [x] Reviewed LC 167 (Two Sum II) — already in repo at `167_TwoSumII_Optimized.cpp`
- [x] User shared LC 26 (Remove Duplicates) solution — **kept code exactly as written**
- [x] Created `02_Two_Pointers/26_RemoveDuplicates.cpp` with user's original code + test harness
- [x] Updated `02_Two_Pointers/README.md` — added File column with links to both solved problems
- [x] Updated `README.md` (main):
  - Badge: Problems Solved `1 → 2`
  - Repo structure tree: added `26_RemoveDuplicates.cpp`
  - Pattern Index: count `1 → 2`
  - Progress Tracker: added LC 26 row
  - How to Run: added LC 26 compile & run example
- [x] Committed & pushed → commit `08d6efb` on `master`

---

### Session 2 — 2026-06-06
**By:** Antigravity
**What was done:**
- [x] User pasted LC 977 (Squares of a Sorted Array) solution
- [x] Kept user's original code exactly as written
- [x] Created `02_Two_Pointers/977_SortedSquares.cpp` with user's code + test harness
- [x] Updated both READMEs (pattern folder + main repo)
- [x] Committed and pushed -> commit `bdf5b18` on master

---

### Session 3 — 2026-06-06
**By:** Antigravity
**What was done:**
- [x] User pasted LC 15 (3Sum) solution
- [x] Kept user's original code exactly as written
- [x] Created `02_Two_Pointers/15_3Sum.cpp` with user's code + test harness
- [x] Updated `02_Two_Pointers/README.md` - added LC 15 row with file link
- [x] Updated `README.md` (main):
  - Badge: Problems Solved `3 → 4`
  - Repo structure tree: added `15_3Sum.cpp`
  - Pattern Index count: `2 → 4`
  - Progress Tracker: added LC 15 row
  - How to Run: added LC 15 compile and run example
- [x] Committed and pushed -> commit `abaf206` on master

---

### Session 4 — 2026-06-06
**By:** Antigravity
**What was done:**
- [x] User pasted LC 16 (3Sum Closest) solution
- [x] Kept user's original code exactly as written
- [x] Created `02_Two_Pointers/16_3SumClosest.cpp` with user's code + test harness
- [x] Updated `02_Two_Pointers/README.md` - added LC 16 row with file link
- [x] Updated `README.md` (main):
  - Badge: Problems Solved `4 → 5`
  - Repo structure tree: added `16_3SumClosest.cpp`
  - Pattern Index count: `4 → 5`
  - Progress Tracker: added LC 16 row
  - How to Run: added LC 16 compile and run example
- [x] Committed and pushed -> commit `3de7ff4` on master

---

### Session 5 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] User pasted LC 75 (Sort Colors) solution
- [x] Kept user's original code exactly as written
- [x] Created `02_Two_Pointers/75_SortColors.cpp` with user's code + test harness
- [x] Updated both READMEs (pattern folder + main repo)
- [x] Committed and pushed -> commit `bffb980` on master

---

### Session 6 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] Created new pattern folder `03_Sliding_Window/`
- [x] Added GFG Max Sum Subarray of size K (fixed-window template problem)
- [x] Created `03_Sliding_Window/MaxSumSubarray_GFG.cpp` with test harness
- [x] Created `03_Sliding_Window/README.md` — full pattern cheat sheet
- [x] Updated main `README.md` — new folder, pattern index, progress tracker
- [x] Committed and pushed -> commit `ee215c5` on master

---

### Session 7 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] User pasted LC 209 (Minimum Size Subarray Sum) solution
- [x] Kept user's original code exactly as written
- [x] Created `03_Sliding_Window/209_MinSizeSubarraySum.cpp` with test harness
- [x] Updated both READMEs (pattern folder + main repo)
- [x] Committed and pushed -> commit `7399a5a` on master

---

### Session 8 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] User pasted GFG Longest K Unique Characters Substring solution
- [x] Kept user's original code exactly as written
- [x] Created `03_Sliding_Window/LongestKSubstr_GFG.cpp` with test harness
- [x] Updated both READMEs
- [x] Committed and pushed -> commit `c6c001f` on master

---

### Session 9 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] User pasted LC 904 (Fruit Into Baskets) solution
- [x] Kept user's original code exactly as written
- [x] Created `03_Sliding_Window/904_FruitIntoBaskets.cpp` with test harness
- [x] Updated both READMEs
- [x] Committed and pushed -> commit `34638f7` on master

---

### Session 10 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] User pasted LC 3 (Longest Substring Without Repeating Characters) solution
- [x] Kept user's original code exactly as written
- [x] Created `03_Sliding_Window/3_LongestSubstringWithoutRepeatingCharacters.cpp` with test harness
- [x] Updated both READMEs
- [x] Committed and pushed -> commit `e537c0f` on master

---

### Session 11 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] User pasted LC 424 (Longest Repeating Character Replacement) solution
- [x] Kept user's original code exactly as written
- [x] Created `03_Sliding_Window/424_LongestRepeatingCharacterReplacement.cpp` with test harness
- [x] Updated both READMEs
- [x] Committed and pushed -> commit `88accec` on master

---

### Session 12 — 2026-06-08
**By:** Antigravity
**What was done:**
- [x] User pasted LC 76 (Minimum Window Substring) solution — Hard
- [x] Kept user's original code exactly as written
- [x] Created `03_Sliding_Window/76_MinimumWindowSubstring.cpp` with test harness
- [x] Updated both READMEs
- [x] Refactored README structure + added `run.ps1` helper script
- [x] Committed and pushed -> commits `f37bbce`, `cfc705b` on master

---

### Session 13 — 2026-06-15
**By:** Antigravity
**What was done:**
- [x] User pasted LC 141 (Linked List Cycle) solution
- [x] Kept user's original code exactly as written
- [x] Created new pattern folder `04_Fast_Slow_Pointers/`
- [x] Created `04_Fast_Slow_Pointers/141_LinkedListCycle.cpp` with 6 test cases
  - Classic cycle (tail → mid)
  - Cycle at head (pos 0)
  - No cycle, two nodes
  - Single node, no self-loop
  - Single node self-loop
  - Empty list (nullptr)
- [x] Created `04_Fast_Slow_Pointers/README.md` — Floyd's pattern cheat sheet
- [x] Updated main `README.md`:
  - Badge: Problems Solved `13 → 14`, Patterns Covered `2 → 3`
  - Repo structure tree: added `04_Fast_Slow_Pointers/`
  - Pattern Index: added row for Fast & Slow Pointers
  - Progress Tracker: added LC 141 row
  - Roadmap: marked Fast & Slow Pointers as done
- [x] All 6/6 tests passing ✅
- [x] Committed and pushed -> commit `8e13867` on master

---

### Session 14 — 2026-06-15
**By:** Antigravity
**What was done:**
- [x] User pasted LC 142 (Linked List Cycle II) solution
- [x] Kept user's original code exactly as written (including `return 0` style for base case)
- [x] Created `04_Fast_Slow_Pointers/142_LinkedListCycleII.cpp` with 6 test cases:
  - Classic cycle, start at index 1
  - Cycle at head (pos 0)
  - No cycle, two nodes
  - Single node, no self-loop
  - Single node self-loop
  - Longer list, cycle at index 2
- [x] Updated `04_Fast_Slow_Pointers/README.md` — added LC 142 row + run command + expected output
- [x] Updated main `README.md`:
  - Badge: Problems Solved `14 → 15`
  - Directory tree: added `142_LinkedListCycleII.cpp`
  - Pattern Index: count `1 → 2` for Fast & Slow Pointers
  - Progress Tracker: added LC 142 row
- [x] All 6/6 tests passing ✅
- [x] Committed and pushed -> commit on master

---

## 🗒️ User Preferences & Notes

- **Do NOT refactor user's solution code** — keep it exactly as written
- **Always update both READMEs** (pattern folder + main repo) when adding a problem
- **Always push to GitHub** after adding a problem
- User prefers C++ solutions
- Repo is on GitHub: `https://github.com/Ashwin-Dev-27/dsa-patterns.git` (branch: `master`)

---

## 🔜 Next Problems to Potentially Add (from Roadmap)

| LC # | Problem | Pattern | Priority |
|------|---------|---------|----------|
| 11  | Container With Most Water | Two Pointers | High |
| 125 | Valid Palindrome | Two Pointers | Medium |
| 42  | Trapping Rain Water | Two Pointers | Hard |
| 142 | Linked List Cycle II (find start of cycle) | Fast & Slow Pointers | ~~High~~ ✅ Done |
| 876 | Middle of the Linked List | Fast & Slow Pointers | Easy |
| 143 | Reorder List | Fast & Slow Pointers | Medium |
| 206 | Reverse Linked List | Linked List | Easy |
| — | Arrays & Hashing folder | 01_Arrays_Hashing | Not started |
