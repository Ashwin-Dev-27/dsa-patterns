# 🗺️ HashMap Pattern — Cheat Sheet

## 📌 When to Use

| Signal in problem | Use HashMap |
|-------------------|-------------|
| "first / last occurrence" | ✅ |
| "frequency / count of elements" | ✅ |
| "two-sum style: find complement" | ✅ |
| "group / classify elements" | ✅ |
| "check if seen before" | ✅ |
| "find duplicate / unique" | ✅ |

---

## 🧱 Core Templates

### 1. Frequency Map (Count occurrences)
```cpp
unordered_map<char, int> freq;
for (char c : s) freq[c]++;

// Then scan for condition
for (char c : s) {
    if (freq[c] == 1) { /* first unique */ }
}
```

### 2. Two-Pass (Build then Query)
```cpp
// Pass 1: build the map
unordered_map<int, int> seen;
for (int x : nums) seen[x]++;

// Pass 2: answer queries
for (int x : nums) {
    if (seen.count(target - x)) { /* found pair */ }
}
```

### 3. Single-Pass (Check while building)
```cpp
unordered_set<int> visited;
for (int x : nums) {
    if (visited.count(x)) return true;   // duplicate found
    visited.insert(x);
}
```

### 4. Group by Key (Anagram / classification)
```cpp
unordered_map<string, vector<string>> groups;
for (string& w : words) {
    string key = w;
    sort(key.begin(), key.end());        // canonical key
    groups[key].push_back(w);
}
```

---

## ⚡ Complexity Guide

| Operation | `unordered_map` | `map` |
|-----------|----------------|-------|
| Insert / lookup | O(1) avg | O(log n) |
| Space | O(n) | O(n) |

> Use `unordered_map` for speed.  
> Use `map` when you need sorted order.

---

## 🔑 Key Tricks

- **`map[key]++`** auto-initialises missing keys to 0 — safe for counting.
- **`map.count(key)`** → 0 or 1, preferred over `map.find() != map.end()`.
- **`map.find(key) != map.end()`** → avoids inserting 0 for missing keys.
- For fixed alphabets (lowercase letters) use `int freq[26] = {}` instead — O(1) space.

---

## 📋 Problems Logged

| LC # | Problem Name | Difficulty | Approach | File |
|------|-------------|------------|----------|------|
| 384 | Ransom Note | 🟢 Easy | Two frequency maps comparison | [`384_RansomNote.cpp`](./384_RansomNote.cpp) |
| 387 | First Unique Character in a String | 🟢 Easy | Frequency map → first count==1 | [`387_FirstUniqueCharacter.cpp`](./387_FirstUniqueCharacter.cpp) |
| 1189 | Maximum Number of Balloons | 🟢 Easy | Frequency map + min division | [`1189_MaximumNumberOfBalloons.cpp`](./1189_MaximumNumberOfBalloons.cpp) |

---

## ▶️ How to Run

```powershell
# LC 387
g++ -std=c++17 -o out 07_HashMap/387_FirstUniqueCharacter.cpp; .\out
.\run.ps1 07_HashMap/387_FirstUniqueCharacter.cpp

# LC 384
g++ -std=c++17 -o out 07_HashMap/384_RansomNote.cpp; .\out
.\run.ps1 07_HashMap/384_RansomNote.cpp

# LC 1189
g++ -std=c++17 -o out 07_HashMap/1189_MaximumNumberOfBalloons.cpp; .\out
.\run.ps1 07_HashMap/1189_MaximumNumberOfBalloons.cpp
```

### Expected Output — LC 1189
```
[PASS]  text="nlaebolko"           expected=1  got=1
[PASS]  text="loonbalxpoonball"   expected=2  got=2
[PASS]  text="leetcode"           expected=0  got=0
[PASS]  text="balloon"            expected=1  got=1
[PASS]  text="balloonballoon"     expected=2  got=2
[PASS]  text="bbaall"             expected=0  got=0
[PASS]  text="bbballlloonnn"      expected=1  got=1
[PASS]  text=""                   expected=0  got=0

8/8 tests passed.
```
