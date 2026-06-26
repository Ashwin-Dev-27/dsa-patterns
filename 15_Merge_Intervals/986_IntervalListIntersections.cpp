/*
 * LC 986 — Interval List Intersections
 * Pattern  : Merge Intervals
 * Difficulty: Medium
 * Approach : Two-pointer scan over both sorted lists
 *            - If intervals overlap, record intersection = [max(s1,s2), min(e1,e2)]
 *            - Advance the pointer whose interval ends first (smaller end)
 *
 * Time  : O(M + N)   — single pass over both lists
 * Space : O(min(M,N)) — output only (result list)
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>result;
        int n = firstList.size();
        int m = secondList.size();
        int i = 0 , j = 0;
        while(i<n and j<m)
        {
            int start_1 = firstList[i][0];
            int end_1 = firstList[i][1];
            int start_2 = secondList[j][0];
            int end_2 = secondList[j][1];

            if(start_1 <= start_2)
            {
                if(end_1 >= start_2)
                {
                    int s = max(start_1,start_2);
                    int e = min(end_1,end_2);
                    result.push_back({s,e});
                }
            }
            else
            {
                if(end_2 >= start_1)
                    {
                        int s = max(start_1,start_2);
                        int e = min(end_1,end_2);
                        result.push_back({s,e});
                    }
            }
        if(end_1 <= end_2)
        i++;
        else
        j++;
        }
        return result;
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
string fmt(const vector<vector<int>>& v) {
    if (v.empty()) return "[]";
    string s = "[";
    for (auto& p : v) s += "[" + to_string(p[0]) + "," + to_string(p[1]) + "],";
    s.back() = ']';
    return s;
}

void check(int t,
           vector<vector<int>> A, vector<vector<int>> B,
           vector<vector<int>> expected,
           const string& label) {
    Solution sol;
    auto got = sol.intervalIntersection(A, B);
    bool pass = (got == expected);
    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t
         << " | " << label
         << "\n       A=" << fmt(A)
         << "  B=" << fmt(B)
         << "\n       got=" << fmt(got)
         << "  expected=" << fmt(expected) << "\n";
}

// ── Test cases ────────────────────────────────────────────────────────────────
int main() {
    // 1. Standard overlap — multiple intersections
    check(1,
          {{0,2},{5,10},{13,23},{24,25}},
          {{1,5},{8,12},{15,24},{25,26}},
          {{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}},
          "multiple overlaps");

    // 2. One list is empty
    check(2,
          {},
          {{1,3},{5,7}},
          {},
          "first list empty -> no intersections");

    // 3. Other list is empty
    check(3,
          {{1,3},{5,7}},
          {},
          {},
          "second list empty -> no intersections");

    // 4. No overlap at all (lists are disjoint)
    check(4,
          {{1,2},{4,5}},
          {{3,3},{6,7}},
          {},
          "completely disjoint lists");

    // 5. Touch-boundary (endpoints equal — should intersect at a point)
    check(5,
          {{1,5}},
          {{5,10}},
          {{5,5}},
          "boundary touch at single point");

    // 6. One interval fully contains the other
    check(6,
          {{1,10}},
          {{3,6}},
          {{3,6}},
          "first fully contains second");

    // 7. Identical single-interval lists
    check(7,
          {{2,7}},
          {{2,7}},
          {{2,7}},
          "identical intervals");

    // 8. Interleaving — every interval in A intersects one in B
    check(8,
          {{0,4},{6,8}},
          {{2,6},{7,9}},
          {{2,4},{6,6},{7,8}},
          "interleaving intervals");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
