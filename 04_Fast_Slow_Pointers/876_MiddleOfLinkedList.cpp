/*
 * ============================================================
 *  LeetCode 876 — Middle of the Linked List
 *  Pattern  : Fast & Slow Pointers
 *  Difficulty: Easy
 *  Link     : https://leetcode.com/problems/middle-of-the-linked-list/
 * ============================================================
 *
 *  PROBLEM
 *  -------
 *  Given the head of a singly linked list, return the MIDDLE node.
 *  If there are two middle nodes, return the SECOND middle node.
 *
 *  INTUITION
 *  ---------
 *  Since we don't know the list length, we can't just go to index N/2.
 *  Instead: run fast at 2x speed alongside slow at 1x speed.
 *  When fast reaches the end, slow is exactly at the middle —
 *  because slow has covered exactly HALF the distance fast has.
 *
 *  APPROACH — Fast & Slow Pointers
 *  ---------------------------------
 *  • Both start at head
 *  • Each iteration: slow += 1, fast += 2
 *  • Loop condition: fast != nullptr AND fast->next != nullptr
 *    - Covers both odd-length lists (fast lands on last node)
 *      and even-length lists (fast->next becomes nullptr)
 *  • When loop ends, slow IS the middle node
 *
 *  ODD vs EVEN LENGTH
 *  -------------------
 *  Odd  (5 nodes): [1] → [2] → [3] → [4] → [5]
 *    After 2 iters: slow=3, fast=5 → fast->next==nullptr → stop → return 3 ✓
 *
 *  Even (6 nodes): [1] → [2] → [3] → [4] → [5] → [6]
 *    After 3 iters: slow=4, fast=nullptr → stop → return 4 (2nd middle) ✓
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(N) — single pass, fast traverses full list once
 *  Space: O(1) — two pointers only
 *
 *  EDGE CASES
 *  ----------
 *  • nullptr head (empty list)
 *  • Single node → middle is itself
 *  • Two nodes → second node is the middle (per problem spec)
 *  • Odd-length list → exact middle
 *  • Even-length list → second of two middles
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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr and fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// ─── Helper: build list from vector ──────────────────────────
ListNode* buildList(vector<int> vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur  = head;
    for (int i = 1; i < (int)vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// ─── Test Runner ─────────────────────────────────────────────
void runTests() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](ListNode* got, int expectedVal, const string& label) {
        ++total;
        bool ok = (got != nullptr && got->val == expectedVal);
        if (ok) ++passed;
        string gotStr = got ? to_string(got->val) : "nullptr";
        cout << (ok ? "[PASS]" : "[FAIL]") << " " << label
             << " → node(" << gotStr << ")"
             << (ok ? "" : " (expected node(" + to_string(expectedVal) + "))")
             << "\n";
    };

    auto checkNull = [&](ListNode* got, const string& label) {
        ++total;
        bool ok = (got == nullptr);
        if (ok) ++passed;
        cout << (ok ? "[PASS]" : "[FAIL]") << " " << label
             << " → " << (got ? to_string(got->val) : "nullptr")
             << (ok ? "" : " (expected nullptr)")
             << "\n";
    };

    // ── Test 1: nullptr (empty list)
    checkNull(sol.middleNode(nullptr), "Test 1 | []              empty list");

    // ── Test 2: Single node → middle = itself
    check(sol.middleNode(buildList({1})), 1,
          "Test 2 | [1]            single node");

    // ── Test 3: Two nodes → second middle (val=2)
    check(sol.middleNode(buildList({1, 2})), 2,
          "Test 3 | [1→2]          even, 2-node   → 2nd middle");

    // ── Test 4: Odd length (5 nodes) → exact middle (val=3)
    check(sol.middleNode(buildList({1, 2, 3, 4, 5})), 3,
          "Test 4 | [1→2→3→4→5]   odd, 5-node    → middle");

    // ── Test 5: Even length (6 nodes) → second middle (val=4)
    check(sol.middleNode(buildList({1, 2, 3, 4, 5, 6})), 4,
          "Test 5 | [1→2→3→4→5→6] even, 6-node   → 2nd middle");

    // ── Test 6: Three nodes → middle (val=2)
    check(sol.middleNode(buildList({1, 2, 3})), 2,
          "Test 6 | [1→2→3]        odd, 3-node    → middle");

    cout << (passed == total ? "\n✅  All " : "\n❌  ")
         << passed << "/" << total << " tests passed.\n";
}

int main() {
    runTests();
    return 0;
}
