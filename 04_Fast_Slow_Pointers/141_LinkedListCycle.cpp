/*
 * ============================================================
 *  LeetCode 141 — Linked List Cycle
 *  Pattern  : Fast & Slow Pointers (Floyd's Cycle Detection)
 *  Difficulty: Easy
 *  Link     : https://leetcode.com/problems/linked-list-cycle/
 * ============================================================
 *
 *  PROBLEM
 *  -------
 *  Given the head of a linked list, determine if the list has a cycle.
 *  A cycle exists if some node can be reached again by following next pointers.
 *
 *  INTUITION
 *  ---------
 *  Imagine two runners on a circular track — one slow, one fast.
 *  If there IS a loop, the fast runner will eventually lap the slow one
 *  and they will meet. If there is NO loop, the fast runner exits the
 *  list and we terminate safely.
 *
 *  APPROACH — Floyd's Cycle Detection
 *  ------------------------------------
 *  • slow pointer advances 1 step per iteration
 *  • fast pointer advances 2 steps per iteration
 *  • If slow == fast at any point → cycle detected → return true
 *  • If fast or fast->next becomes nullptr → no cycle → return false
 *
 *  WHY TWO BASE CASES?
 *  --------------------
 *  head == nullptr      → empty list, trivially no cycle
 *  head->next == nullptr→ single node with no self-loop, trivially no cycle
 *  (These are handled implicitly by the while condition too, but kept
 *   explicitly for clarity and early exit.)
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(N)  — in the worst case (no cycle), fast traverses the list once
 *                 in a cycle, fast catches slow in at most N steps
 *  Space: O(1)  — only two pointers, no extra data structures
 *
 *  EDGE CASES
 *  ----------
 *  • Empty list (head == nullptr)
 *  • Single node, no self-loop (head->next == nullptr)
 *  • Single node pointing to itself (cycle of length 1)
 *  • Cycle starting at the very first node (e.g. tail → head)
 *  • Cycle deep in the list (not at head)
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

// ─── ListNode Definition ──────────────────────────────────────
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ─── Solution ────────────────────────────────────────────────
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Base cases: empty list or single non-looping node
        if (head == nullptr)       return false;
        if (head->next == nullptr) return false;

        ListNode* slow = head;  // moves 1 step at a time
        ListNode* fast = head;  // moves 2 steps at a time

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // 1 step
            fast = fast->next->next;  // 2 steps

            if (slow == fast)         // pointers met → cycle!
                return true;
        }

        return false;  // fast fell off the end → no cycle
    }
};

// ─── Test Runner ─────────────────────────────────────────────
void runTests() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](bool got, bool expected, const string& label) {
        ++total;
        bool ok = (got == expected);
        if (ok) ++passed;
        cout << (ok ? "[PASS]" : "[FAIL]") << " " << label
             << " → " << (got ? "true" : "false")
             << (ok ? "" : " (expected " + string(expected ? "true" : "false") + ")")
             << "\n";
    };

    // ── Test 1: Classic cycle — tail → node at index 1
    {
        // 3 → 2 → 0 → -4 ↩ (back to index 1)
        ListNode* n1 = new ListNode(3);
        ListNode* n2 = new ListNode(2);
        ListNode* n3 = new ListNode(0);
        ListNode* n4 = new ListNode(-4);
        n1->next = n2; n2->next = n3; n3->next = n4;
        n4->next = n2;   // cycle: -4 → 2
        check(sol.hasCycle(n1), true, "Test 1 | [3→2→0→-4]→2 (cycle at pos 1)");
        // NOTE: intentional memory leak in tests for brevity
    }

    // ── Test 2: Cycle at head (pos 0)
    {
        ListNode* n1 = new ListNode(1);
        ListNode* n2 = new ListNode(2);
        n1->next = n2;
        n2->next = n1;   // cycle: 2 → 1
        check(sol.hasCycle(n1), true, "Test 2 | [1→2]→1 (cycle at pos 0)");
    }

    // ── Test 3: No cycle, two nodes
    {
        ListNode* n1 = new ListNode(1);
        ListNode* n2 = new ListNode(2);
        n1->next = n2;
        check(sol.hasCycle(n1), false, "Test 3 | [1→2] (no cycle)");
    }

    // ── Test 4: Single node, no self-loop
    {
        ListNode* n1 = new ListNode(1);
        check(sol.hasCycle(n1), false, "Test 4 | [1] (single node, no loop)");
    }

    // ── Test 5: Single node, self-loop
    {
        ListNode* n1 = new ListNode(1);
        n1->next = n1;   // self-loop
        check(sol.hasCycle(n1), true, "Test 5 | [1→1] (self-loop)");
    }

    // ── Test 6: Empty list
    {
        check(sol.hasCycle(nullptr), false, "Test 6 | nullptr (empty list)");
    }

    cout << (passed == total ? "\n✅  All " : "\n❌  ")
         << passed << "/" << total << " tests passed.\n";
}

int main() {
    runTests();
    return 0;
}
