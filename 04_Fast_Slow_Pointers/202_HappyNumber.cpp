/*
 * ============================================================
 *  LeetCode 202 — Happy Number
 *  Pattern  : Fast & Slow Pointers (Floyd's Cycle Detection)
 *  Difficulty: Easy
 *  Link     : https://leetcode.com/problems/happy-number/
 * ============================================================
 *
 *  PROBLEM
 *  -------
 *  A number is "happy" if repeatedly replacing it with the sum of
 *  squares of its digits eventually reaches 1.
 *  If it loops forever without reaching 1, it is "unhappy".
 *  Return true if n is a happy number, false otherwise.
 *
 *  INTUITION
 *  ---------
 *  The sequence of digit-square sums either:
 *    (a) Reaches 1  → happy ✅
 *    (b) Enters a cycle that never reaches 1  → unhappy ❌
 *
 *  This is the same structure as a linked list with a cycle!
 *  Apply Floyd's Tortoise & Hare on the sequence:
 *    slow takes 1 step  → fun(slow)
 *    fast takes 2 steps → fun(fun(fast))
 *
 *  If fast ever hits 1 → happy.
 *  If slow == fast (and ≠ 1) → cycle detected → unhappy.
 *
 *  APPROACH
 *  --------
 *  • fun(n): computes sum of squares of digits of n
 *  • Both slow and fast start at n
 *  • Loop: advance slow 1 step, fast 2 steps
 *    - if fast == 1  → return true
 *    - if slow == fast (and ≠ 1) → return false
 *
 *  COMPLEXITY
 *  ----------
 *  Time : O(log n) per step, O(log n) total steps → effectively O(log n)
 *  Space: O(1) — two pointers, no set needed
 *
 *  EDGE CASES
 *  ----------
 *  • n = 1  → already happy, fast starts at 1 → loop condition false → true
 *  • Small unhappy numbers (e.g. 2, 3) → cycle detected quickly
 *  • Large happy numbers → fast reaches 1 first
 * ============================================================
 */

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// ─── Solution (user's original code, preserved exactly) ──────
class Solution {
public:
    int fun(int n)
    {
        int sum = 0;
        while(n>0)
        {
            int d = n%10;
            n = n/10;
            sum = sum+d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast!= 1)
        {
            slow = fun(slow);
            fast = fun(fast);
            fast = fun(fast);

            if(slow==fast and slow!=1)
            return false;
        }
        return true;
    }
};

// ─── Test Runner ─────────────────────────────────────────────
void runTests() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](int n, bool expected, const string& label) {
        ++total;
        bool got = sol.isHappy(n);
        bool ok  = (got == expected);
        if (ok) ++passed;
        string gotStr = got ? "true" : "false";
        string expStr = expected ? "true" : "false";
        cout << (ok ? "[PASS]" : "[FAIL]") << " " << label
             << " → " << gotStr
             << (ok ? "" : " (expected " + expStr + ")")
             << "\n";
    };

    // ── Test 1: n=1 → already happy
    check(1,  true,  "Test 1 | n=1                   → happy");

    // ── Test 2: n=19 → happy  (1²+9²=82 → 68 → 100 → 1)
    check(19, true,  "Test 2 | n=19                  → happy");

    // ── Test 3: n=7 → happy
    check(7,  true,  "Test 3 | n=7                   → happy");

    // ── Test 4: n=2 → unhappy (enters cycle: 4→16→37→58→89→145→42→20→4)
    check(2,  false, "Test 4 | n=2                   → unhappy");

    // ── Test 5: n=4 → unhappy (same cycle as above)
    check(4,  false, "Test 5 | n=4                   → unhappy");

    // ── Test 6: n=100 → happy  (1²+0²+0²=1)
    check(100, true, "Test 6 | n=100                 → happy");

    cout << (passed == total ? "\n✅  All " : "\n❌  ")
         << passed << "/" << total << " tests passed.\n";
}

int main() {
    runTests();
    return 0;
}
