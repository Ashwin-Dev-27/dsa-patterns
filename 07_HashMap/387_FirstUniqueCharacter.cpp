/*
 * LC 387 — First Unique Character in a String
 * Pattern : HashMap (Frequency Count)
 * Difficulty : Easy
 *
 * Approach:
 *   Pass 1 — build frequency map: f[char] = count
 *   Pass 2 — return index of first char whose count == 1
 *   Return -1 if no unique character exists
 *
 * Time  : O(n)  — two linear scans
 * Space : O(1)  — at most 26 lowercase-letter keys in the map
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ────────────────────────────────────
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>f;
        for(int i =0;i<s.size(); i++)
        f[s[i]]++;

        for(int i =0; i<s.size(); i++)
        {
         if(f[s[i]]==1)
         return i;
        }
        return -1;
    }
};
// ────────────────────────────────────────────────────────────────────────────

int main() {
    Solution sol;
    int passed = 0, total = 0;

    auto check = [&](string s, int expected) {
        total++;
        int result = sol.firstUniqChar(s);
        bool ok = (result == expected);
        if (ok) passed++;
        cout << (ok ? "[PASS]" : "[FAIL]")
             << "  s=\"" << s << "\""
             << "  expected=" << expected
             << "  got=" << result << "\n";
    };

    // Test 1 — LC example 1: first unique is 'l' at index 0
    check("leetcode", 0);

    // Test 2 — LC example 2: all chars repeat, no unique → -1
    check("aabb", -1);

    // Test 3 — LC example 3: first unique is 'v' at index 2
    check("loveleetcode", 2);

    // Test 4 — single character: it is itself unique → 0
    check("z", 0);

    // Test 5 — all same characters: no unique → -1
    check("aaaa", -1);

    // Test 6 — unique character is at the very end
    check("aabbccdde", 8);

    // Test 7 — unique character is in the middle
    check("aabbc", 4);

    // Test 8 — only 'd' is unique (a=2,b=2,c=2,d=1) → index 6
    check("abacbcd", 6);

    cout << "\n" << passed << "/" << total << " tests passed.\n";
    return (passed == total) ? 0 : 1;
}
