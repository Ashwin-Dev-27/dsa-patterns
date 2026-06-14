/*
 * ============================================================
 *  LeetCode 142 — Linked List Cycle II
 *  Pattern  : Fast & Slow Pointers (Floyd's — Phase 2)
 *  Difficulty: Medium
 *  Link     : https://leetcode.com/problems/linked-list-cycle-ii/
 * ============================================================
 *
 *  PROBLEM
 *  -------
 *  Given the head of a linked list that may contain a cycle,
 *  return the NODE where the cycle begins.
 *  If no cycle exists, return nullptr.
 *
 *  APPROACH — Floyd's Two-Phase Algorithm
 *  ----------------------------------------
 *  Phase 1 — Find Meeting Point (same as LC 141)
 *    • slow moves 1 step, fast moves 2 steps
 *    • If they meet → cycle exists; meeting point is inside the cycle
 *    • If fast falls off → no cycle → return nullptr
 *
 *  Phase 2 — Find Cycle Start
 *    • Reset slow to head; keep fast at meeting point
 *    • Now advance BOTH one step at a time
 *    • The node where they meet again is the START of the cycle
 *
 *  WHY DOES PHASE 2 WORK? (The Math)
 *  ----------------------------------
 *  Let:
 *    F = distance from head to cycle start
 *    C = length of the cycle
 *    a = distance from cycle start to meeting point (inside cycle)
 *
 *  At the meeting point:
 *    slow traveled: F + a
 *    fast traveled: F + a + C  (fast did one full extra loop)
 *    Since fast = 2 × slow: 2(F + a) = F + a + C
 *    → F = C - a
 *
 *  So distance from head to cycle start (F)
 *  equals distance from meeting point back to cycle start (C - a).
 *  Moving both pointers one step at a time will make them converge
 *  exactly at the cycle start.
 *
 *  NOTE ON `return 0`
 *  ------------------
 *  In C++, returning `0` from a pointer-returning function is valid
 *  (0 converts to nullptr), but `return nullptr` is preferred for
 *  clarity. Kept as-is to preserve user's original style; only
 *  the test harness uses nullptr explicitly.
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(N)  — Phase 1 + Phase 2 each touch at most N nodes
 *  Space: O(1)  — two pointers only
 *
 *  EDGE CASES
 *  ----------
 *  • nullptr head
 *  • Single node with no self-loop → no cycle
 *  • Single node self-loop → cycle starts at head
 *  • Cycle starting at head (pos 0)
 *  • Cycle starting mid-list
 *  • Cycle at the very last node (tail → head)
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// ─── ListNode Definition ──────────────────────────────────────
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ─── Solution (user's original code, preserved exactly) ──────
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr or head->next == nullptr)
            return 0;                          // user's style: 0 == nullptr

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr and fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;               // Phase 2: reset slow to head
                while (slow != fast)
                {
                    slow = slow->next;     // both move 1 step
                    fast = fast->next;
                }
                return slow;               // meeting point = cycle start
            }
        }
        return nullptr;
    }
};

// ─── Test Runner ─────────────────────────────────────────────
void runTests() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](ListNode* got, ListNode* expected, const string& label) {
        ++total;
        bool ok = (got == expected);
        if (ok) ++passed;
        string gotStr      = got      ? to_string(got->val)      : "nullptr";
        string expectedStr = expected ? to_string(expected->val) : "nullptr";
        cout << (ok ? "[PASS]" : "[FAIL]") << " " << label
             << " → node(" << gotStr << ")"
             << (ok ? "" : " (expected node(" + expectedStr + "))")
             << "\n";
    };

    // ── Test 1: Cycle starts at index 1 (val=2)
    // List: 3 → 2 → 0 → -4 ↩ (back to node val=2)
    {
        ListNode* n1 = new ListNode(3);
        ListNode* n2 = new ListNode(2);   // ← cycle start
        ListNode* n3 = new ListNode(0);
        ListNode* n4 = new ListNode(-4);
        n1->next = n2; n2->next = n3; n3->next = n4;
        n4->next = n2;   // tail → cycle start
        check(sol.detectCycle(n1), n2, "Test 1 | [3→2→0→-4]→2  cycle start = node(2)");
    }

    // ── Test 2: Cycle starts at head (pos 0, val=1)
    // List: 1 → 2 ↩ (back to node val=1)
    {
        ListNode* n1 = new ListNode(1);   // ← cycle start = head
        ListNode* n2 = new ListNode(2);
        n1->next = n2;
        n2->next = n1;   // tail → head
        check(sol.detectCycle(n1), n1, "Test 2 | [1→2]→1       cycle start = node(1)");
    }

    // ── Test 3: No cycle — two nodes
    {
        ListNode* n1 = new ListNode(1);
        ListNode* n2 = new ListNode(2);
        n1->next = n2;
        check(sol.detectCycle(n1), nullptr, "Test 3 | [1→2]          no cycle   = nullptr");
    }

    // ── Test 4: Single node, no self-loop
    {
        ListNode* n1 = new ListNode(1);
        check(sol.detectCycle(n1), nullptr, "Test 4 | [1]            no cycle   = nullptr");
    }

    // ── Test 5: Single node self-loop (cycle start = head)
    {
        ListNode* n1 = new ListNode(1);
        n1->next = n1;
        check(sol.detectCycle(n1), n1, "Test 5 | [1→1]          cycle start = node(1)");
    }

    // ── Test 6: Longer list, cycle starts at index 2 (val=0)
    // List: 1 → 2 → 3 → 4 → 5 ↩ (back to node val=3)
    {
        ListNode* a = new ListNode(1);
        ListNode* b = new ListNode(2);
        ListNode* c = new ListNode(3);   // ← cycle start
        ListNode* d = new ListNode(4);
        ListNode* e = new ListNode(5);
        a->next = b; b->next = c; c->next = d; d->next = e;
        e->next = c;   // tail → cycle start (index 2)
        check(sol.detectCycle(a), c, "Test 6 | [1→2→3→4→5]→3  cycle start = node(3)");
    }

    cout << (passed == total ? "\n✅  All " : "\n❌  ")
         << passed << "/" << total << " tests passed.\n";
}

int main() {
    runTests();
    return 0;
}
