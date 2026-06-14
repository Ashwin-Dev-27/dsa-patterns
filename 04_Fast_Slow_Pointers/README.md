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

---

## 🚀 How to Run

```bash
# Generic pattern
g++ -std=c++17 -o solution <file.cpp> && ./solution
```

| Problem | Command |
|---------|---------|
| LC 141 | `g++ -std=c++17 -o solution 141_LinkedListCycle.cpp && ./solution` |

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
</details>
