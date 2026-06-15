/*
 * ============================================================
 *  LeetCode 287 — Find the Duplicate Number
 *  Pattern  : Fast & Slow Pointers (Floyd's Cycle Detection)
 *  Difficulty: Medium
 *  Link     : https://leetcode.com/problems/find-the-duplicate-number/
 * ============================================================
 *
 *  PROBLEM
 *  -------
 *  Given an array nums of n+1 integers where each integer is in [1, n],
 *  there is exactly ONE repeated number. Find and return it.
 *  Must use O(1) extra space (no hash set!) and not modify the array.
 *
 *  INTUITION
 *  ---------
 *  Think of the array as a linked list where index i points to nums[i].
 *  Example: nums = [1, 3, 4, 2, 2]
 *    0 → nums[0]=1 → nums[1]=3 → nums[3]=2 → nums[2]=4 → nums[4]=2 → ... (cycle!)
 *
 *  The duplicate value IS the entry point of the cycle — because two
 *  indices point to the same value, meaning two "nodes" share the same
 *  next pointer. This is exactly the structure Floyd's Phase 2 detects.
 *
 *  APPROACH — Floyd's Cycle Detection (Two Phases)
 *  ------------------------------------------------
 *  Phase 1 (Find meeting point inside cycle):
 *    • Both slow and fast start at index 0
 *    • slow = nums[slow]        (1 step)
 *    • fast = nums[nums[fast]]  (2 steps)
 *    • Loop until slow == fast  → they're inside the cycle
 *
 *  Phase 2 (Find cycle entry = duplicate):
 *    • Reset slow to 0; keep fast at meeting point
 *    • Both move 1 step at a time
 *    • When slow == fast → that index is the duplicate
 *
 *  WHY PHASE 2 WORKS
 *  -----------------
 *  If the distance from start→cycle_entry is F, and the meeting point is
 *  at distance C from the cycle entry, then:
 *    slow traveled: F + C
 *    fast traveled: F + C + nL  (n full loops of length L)
 *    fast = 2 * slow  →  F = nL - C
 *  So resetting slow to 0 and advancing both 1 step makes them meet at
 *  exactly the cycle entry after F more steps.
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(N) — two linear passes at most
 *  Space: O(1) — two pointers only, array unmodified
 *
 *  EDGE CASES
 *  ----------
 *  • Duplicate appears more than twice — still works (single entry point)
 *  • Duplicate is at index 1 or near the start — Phase 2 finds it quickly
 *  • All values the same (except one) — cycle entry still correct
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// ─── Solution (user's original code, preserved exactly) ──────
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow,fast;
        slow = 0;
        fast = 0;
        while(true)
        {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow==fast)
            {
                slow = 0;
                while(slow!=fast)
                {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow;
            }        
        }
    }
};

// ─── Test Runner ─────────────────────────────────────────────
void runTests() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](vector<int> nums, int expected, const string& label) {
        ++total;
        int got = sol.findDuplicate(nums);
        bool ok = (got == expected);
        if (ok) ++passed;
        cout << (ok ? "[PASS]" : "[FAIL]") << " " << label
             << " → " << got
             << (ok ? "" : " (expected " + to_string(expected) + ")")
             << "\n";
    };

    // ── Test 1: classic example — duplicate is 2
    check({1, 3, 4, 2, 2}, 2,
          "Test 1 | [1,3,4,2,2]                → duplicate = 2");

    // ── Test 2: classic example — duplicate is 3
    check({3, 1, 3, 4, 2}, 3,
          "Test 2 | [3,1,3,4,2]                → duplicate = 3");

    // ── Test 3: duplicate at beginning (1)
    check({1, 1}, 1,
          "Test 3 | [1,1]                      → duplicate = 1");

    // ── Test 4: duplicate appears more than twice
    check({2, 2, 2, 2, 2}, 2,
          "Test 4 | [2,2,2,2,2]                → duplicate = 2");

    // ── Test 5: larger array — duplicate is 4
    check({4, 3, 1, 4, 2}, 4,
          "Test 5 | [4,3,1,4,2]                → duplicate = 4");

    // ── Test 6: duplicate near end of value range
    check({1, 2, 3, 4, 5, 6, 5}, 5,
          "Test 6 | [1,2,3,4,5,6,5]            → duplicate = 5");

    cout << (passed == total ? "\n✅  All " : "\n❌  ")
         << passed << "/" << total << " tests passed.\n";
}

int main() {
    runTests();
    return 0;
}
