# ⚡ Fast & Slow Pointers Pattern

## When to Use

Use **Fast & Slow Pointers** (also called the **Floyd's Tortoise and Hare** algorithm) when dealing with **cyclic linked lists or arrays**, or when you need to find a **specific position** in a linked list (like the middle or the k-th node from end) in a single pass without knowing the length.

The key insight: **two pointers moving at different speeds will eventually meet** if (and only if) there is a cycle.

## Core Idea

```
slow → moves 1 step per iteration
fast → moves 2 steps per iteration
```

### Cycle Detection
- If a cycle exists, fast will eventually lap slow and they will **meet inside the cycle**
- If no cycle, fast will **fall off the end** (`fast == nullptr` or `fast->next == nullptr`)

### Middle of Linked List
- When fast reaches the end, slow is exactly at the **middle**
- This works because slow covers half the distance fast covers

---

## Common Keywords to Look For

| Keyword / Phrase               | Why It Signals Fast & Slow Pointers        |
| ------------------------------ | ------------------------------------------ |
| **"cycle in linked list"**     | Classic Floyd's cycle detection            |
| **"middle of linked list"**    | Fast reaches end while slow is at middle   |
| **"k-th node from end"**       | Offset two pointers by k steps             |
| **"detect start of cycle"**    | Phase 2 of Floyd's: reset one pointer      |
| **"happy number"**             | Cycle detection on number sequences        |
| **"find duplicate (no extra space)"** | Array-as-linked-list + Floyd's      |

---

## Complexity Cheat Sheet

| Variant               | Time  | Space |
| --------------------- | ----- | ----- |
| Cycle Detection       | O(N)  | O(1)  |
| Find Middle           | O(N)  | O(1)  |
| Find Cycle Start      | O(N)  | O(1)  |
| K-th from End         | O(N)  | O(1)  |

---

## Classic Problems in This Pattern

| LC # | Problem Name                        | Difficulty | File |
| ---- | ----------------------------------- | ---------- | ---- |
| 141  | Linked List Cycle                   | 🟢 Easy    | [141_LinkedListCycle.cpp](./141_LinkedListCycle.cpp) |
| 142  | Linked List Cycle II                | 🟡 Medium  | [142_LinkedListCycleII.cpp](./142_LinkedListCycleII.cpp) |
| 876  | Middle of the Linked List           | 🟢 Easy    | [876_MiddleOfLinkedList.cpp](./876_MiddleOfLinkedList.cpp) |
| 287  | Find the Duplicate Number           | 🟡 Medium  | [287_FindDuplicateNumber.cpp](./287_FindDuplicateNumber.cpp) |
| 202  | Happy Number                        | 🟢 Easy    | [202_HappyNumber.cpp](./202_HappyNumber.cpp) |

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 141 | `g++ -std=c++17 -o solution 141_LinkedListCycle.cpp && ./solution` |
| LC 142 | `g++ -std=c++17 -o solution 142_LinkedListCycleII.cpp && ./solution` |
| LC 876 | `g++ -std=c++17 -o solution 876_MiddleOfLinkedList.cpp && ./solution` |
| LC 287 | `g++ -std=c++17 -o solution 287_FindDuplicateNumber.cpp && ./solution` |
| LC 202 | `g++ -std=c++17 -o solution 202_HappyNumber.cpp && ./solution` |

<details>
<summary>Expected output for all problems</summary>

**LC 141**
```
[PASS] Test 1 | [3→2→0→-4]→2 (cycle at pos 1) → true
[PASS] Test 2 | [1→2]→1 (cycle at pos 0) → true
[PASS] Test 3 | [1→2] (no cycle) → false
[PASS] Test 4 | [1] (single node, no loop) → false
[PASS] Test 5 | [1→1] (self-loop) → true
[PASS] Test 6 | nullptr (empty list) → false

✅  All 6/6 tests passed.
```
**LC 142**
```
[PASS] Test 1 | [3→2→0→-4]→2  cycle start = node(2) → node(2)
[PASS] Test 2 | [1→2]→1       cycle start = node(1) → node(1)
[PASS] Test 3 | [1→2]          no cycle   = nullptr → nullptr
[PASS] Test 4 | [1]            no cycle   = nullptr → nullptr
[PASS] Test 5 | [1→1]          cycle start = node(1) → node(1)
[PASS] Test 6 | [1→2→3→4→5]→3  cycle start = node(3) → node(3)

✅  All 6/6 tests passed.
```
**LC 876**
```
[PASS] Test 1 | []              empty list → nullptr
[PASS] Test 2 | [1]            single node → node(1)
[PASS] Test 3 | [1→2]          even, 2-node   → 2nd middle → node(2)
[PASS] Test 4 | [1→2→3→4→5]   odd, 5-node    → middle → node(3)
[PASS] Test 5 | [1→2→3→4→5→6] even, 6-node   → 2nd middle → node(4)
[PASS] Test 6 | [1→2→3]        odd, 3-node    → middle → node(2)

✅  All 6/6 tests passed.
```
**LC 287**
```
[PASS] Test 1 | [1,3,4,2,2]                → duplicate = 2 → 2
[PASS] Test 2 | [3,1,3,4,2]                → duplicate = 3 → 3
[PASS] Test 3 | [1,1]                      → duplicate = 1 → 1
[PASS] Test 4 | [2,2,2,2,2]                → duplicate = 2 → 2
[PASS] Test 5 | [4,3,1,4,2]                → duplicate = 4 → 4
[PASS] Test 6 | [1,2,3,4,5,6,5]            → duplicate = 5 → 5

✅  All 6/6 tests passed.
```
**LC 202**
```
[PASS] Test 1 | n=1                   → happy → true
[PASS] Test 2 | n=19                  → happy → true
[PASS] Test 3 | n=7                   → happy → true
[PASS] Test 4 | n=2                   → unhappy → false
[PASS] Test 5 | n=4                   → unhappy → false
[PASS] Test 6 | n=100                 → happy → true

✅  All 6/6 tests passed.
```
</details>
