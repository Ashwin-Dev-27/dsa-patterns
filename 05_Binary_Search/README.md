# 📚 Pattern 05 — Binary Search

## 🧠 Core Idea
**Binary Search** works on a **sorted** (or monotonically ordered) search space.
Instead of scanning every element O(n), you repeatedly halve the space → **O(log n)**.

The key insight: at each step, you can **eliminate half** the remaining candidates based on a condition.

---

## 🔑 When to Use Binary Search

| Signal in the problem | Pattern |
|-----------------------|---------|
| Array is **sorted** / rotated sorted | Classic Binary Search |
| "Find first / last occurrence of X" | Binary Search on answer |
| "Minimum / maximum value that satisfies condition" | Binary Search on answer |
| "Search in rotated sorted array" | Modified Binary Search |
| "Find peak element" | Binary Search on condition |
| Answer space is a **range of integers** (not just array indices) | Binary Search on answer |

---

## 📐 Templates

### 1 — Classic (find exact target)
```cpp
int binarySearch(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   // avoids overflow
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target)    lo = mid + 1;
        else                            hi = mid - 1;
    }
    return -1;   // not found
}
```

### 2 — Lower Bound (first position where nums[mid] >= target)
```cpp
int lowerBound(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();   // hi = size (open right boundary)
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else                    hi = mid;
    }
    return lo;   // first index >= target
}
```

### 3 — Upper Bound (first position where nums[mid] > target)
```cpp
int upperBound(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= target) lo = mid + 1;
        else                     hi = mid;
    }
    return lo;   // first index > target
}
```

### 4 — Binary Search on Answer (minimise/maximise)
```cpp
// "Find minimum X such that condition(X) is true"
int lo = minPossible, hi = maxPossible, ans = hi;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (condition(mid)) { ans = mid; hi = mid - 1; }  // try smaller
    else                { lo = mid + 1; }
}
return ans;
```

### 5 — Rotated Sorted Array
```cpp
// One half is always normally sorted — identify which side, then binary search it
int lo = 0, hi = nums.size() - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] == target) return mid;
    if (nums[lo] <= nums[mid]) {           // left half sorted
        if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
        else                                           lo = mid + 1;
    } else {                               // right half sorted
        if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
        else                                           hi = mid - 1;
    }
}
return -1;
```

### 6 — Mountain / Peak (slope comparison)
```cpp
int peakIndexInMountainArray(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < arr[mid + 1]) lo = mid + 1;  // still ascending → peak is right
        else                         hi = mid;      // descending → peak is mid or left
    }
    return lo;   // lo == hi at the peak
}
```

---

## ⚡ Complexity

| Case | Time | Space |
|------|------|-------|
| All variants | O(log n) | O(1) |

---

## ⚠️ Common Pitfalls

| Mistake | Fix |
|---------|-----|
| `mid = (lo + hi) / 2` — integer overflow | Use `lo + (hi - lo) / 2` |
| Off-by-one on boundary (`<` vs `<=`) | Use `lo <= hi` for exact match; `lo < hi` for bound search |
| Forgetting duplicates | Use lower/upper bound templates instead of classic |
| Wrong condition for rotated array | Always identify which half is sorted first |

---

## 🔑 Key Tricks

- **`mid = lo + (hi - lo) / 2`** — always use this, never `(lo+hi)/2`
- For **"first true"** problems: shrink `hi` when condition is true → `ans = mid; hi = mid - 1`
- For **"last true"** problems: shrink `lo` when condition is true → `ans = mid; lo = mid + 1`
- Binary search works on **any monotonic function**, not just sorted arrays

---

## 📋 Problems Logged

| LC # | Problem Name | Difficulty | Approach | File |
|------|-------------|------------|----------|------|
| 162 | Find Peak Element | 🟡 Medium | Slope comparison — any local peak is valid, converge to `low == high` | [`162_FindPeakElement.cpp`](./162_FindPeakElement.cpp) |
| 704 | Binary Search | 🟢 Easy | Classic — low/high convergence, `(low+high)/2` mid | [`704_BinarySearch.cpp`](./704_BinarySearch.cpp) |
| 852 | Peak Index in a Mountain Array | 🟡 Medium | Slope comparison — `arr[mid]` vs `arr[mid+1]`, converge to `low == high` | [`852_PeakIndexInMountainArray.cpp`](./852_PeakIndexInMountainArray.cpp) |

---

## ▶️ How to Run

```powershell
# LC 162
g++ -std=c++17 -o out 05_Binary_Search/162_FindPeakElement.cpp; .\out
.\run.ps1 05_Binary_Search/162_FindPeakElement.cpp

# LC 704
g++ -std=c++17 -o out 05_Binary_Search/704_BinarySearch.cpp; .\out
.\run.ps1 05_Binary_Search/704_BinarySearch.cpp

# LC 852
g++ -std=c++17 -o out 05_Binary_Search/852_PeakIndexInMountainArray.cpp; .\out
.\run.ps1 05_Binary_Search/852_PeakIndexInMountainArray.cpp
```

### Expected Output — LC 162
```
[PASS]  nums=[1,2,3,1]                 expected=2  got=2
[PASS]  nums=[1,2,1,3,5,6,4]           expected=5  got=5
[PASS]  nums=[1]                       expected=0  got=0
[PASS]  nums=[1,2]                     expected=1  got=1
[PASS]  nums=[2,1]                     expected=0  got=0
[PASS]  nums=[-1,-2,-3,-4]             expected=0  got=0
[PASS]  nums=[1,2,3,4]                 expected=3  got=3
[PASS]  nums=[1,3,2,4,5,2]             expected=4  got=4

8/8 tests passed.
```

### Expected Output — LC 704
```
[PASS]  nums=[-1,0,3,5,9,12]  target=9   expected=4  got=4
[PASS]  nums=[-1,0,3,5,9,12]  target=2   expected=-1  got=-1
[PASS]  nums=[5]               target=5   expected=0  got=0
[PASS]  nums=[5]               target=3   expected=-1  got=-1
[PASS]  nums=[1,3,5,7,9]       target=1   expected=0  got=0
[PASS]  nums=[1,3,5,7,9]       target=9   expected=4  got=4
[PASS]  nums=[1,3,5,7,9]       target=5   expected=2  got=2
[PASS]  nums=[-10,-5,0,3,7]    target=-20 expected=-1  got=-1

8/8 tests passed.
```

### Expected Output — LC 852
```
[PASS]  arr=[0,1,0]                 expected=1  got=1
[PASS]  arr=[0,2,1,0]               expected=1  got=1
[PASS]  arr=[0,10,5,2]              expected=1  got=1
[PASS]  arr=[3,5,4]                 expected=1  got=1
[PASS]  arr=[1,2,4,3]               expected=2  got=2
[PASS]  arr=[1,3,2]                 expected=1  got=1
[PASS]  arr=[1,2,3,4,5,3,1]         expected=4  got=4
[PASS]  arr=[-5,-3,-1,-2,-4]        expected=2  got=2

8/8 tests passed.
```
