/*
 * GFG — Check if Any Two Intervals Overlap
 * Pattern  : Merge Intervals
 * Difficulty: Medium
 * Link     : https://www.geeksforgeeks.org/check-if-any-two-intervals-overlap-among-a-given-set-of-intervals/
 * Approach : Sort by start time, then scan adjacent pairs tracking the running
 *            max-end. If any next start <= current max-end → overlap found.
 *
 * Time  : O(N log N)  — dominated by sort
 * Space : O(1)        — no extra data structures
 */

#include <bits/stdc++.h>
using namespace std;

// ── User's original solution (unchanged) ─────────────────────────────────────
class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        int start_1 = intervals[0][0];
        int end_1 = intervals[0][1];
        
        for(int i =1 ; i<n ; i++)
        {
            int start_2 = intervals[i][0];
            int end_2 = intervals[i][1];
            
            if(end_1 >= start_2)
            {
                return true;
            }
            start_1 = start_1;
            end_1 = max(end_1,end_2);
        }
        return false;
    }
};
// ─────────────────────────────────────────────────────────────────────────────

// ── Helpers ──────────────────────────────────────────────────────────────────
void check(int t,
           vector<vector<int>> intervals,
           bool expected,
           const string& label) {
    Solution sol;
    bool got = sol.isIntersect(intervals);
    bool pass = (got == expected);
    cout << (pass ? "[PASS]" : "[FAIL]") << " Test " << t
         << " | " << label
         << " -> " << (got ? "true" : "false")
         << "  (expected: " << (expected ? "true" : "false") << ")\n";
}

// ── Test cases ────────────────────────────────────────────────────────────────
int main() {
    // 1. Classic overlap — two intervals clearly overlap
    check(1, {{1,3},{2,4}}, true,
          "classic overlap [1,3] & [2,4]");

    // 2. No overlap — all intervals disjoint
    check(2, {{1,2},{3,4},{5,6}}, false,
          "completely disjoint intervals");

    // 3. Boundary touch — endpoints meet (end == start → overlap)
    check(3, {{1,2},{2,3}}, true,
          "boundary touch end==start counts as overlap");

    // 4. Single interval — cannot overlap with itself
    check(4, {{1,5}}, false,
          "single interval -> no overlap possible");

    // 5. One interval fully contains another
    check(5, {{1,10},{3,6}}, true,
          "first fully contains second");

    // 6. Unsorted input — overlap only visible after sorting
    check(6, {{5,8},{1,3},{2,6}}, true,
          "unsorted input with overlap after sort");

    // 7. No overlap with multiple intervals (wide gaps)
    check(7, {{1,2},{10,11},{20,21},{30,31}}, false,
          "multiple wide-gap disjoint intervals");

    // 8. Last two intervals overlap, earlier ones don't
    check(8, {{1,2},{5,6},{4,7}}, true,
          "overlap only between later intervals");

    cout << "\n✅  All tests executed.\n";
    return 0;
}
