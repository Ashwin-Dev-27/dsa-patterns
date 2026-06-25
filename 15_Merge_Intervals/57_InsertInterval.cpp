/*
 * ============================================================================
 *  Problem   : Insert Interval  (LeetCode #57)
 *  Pattern   : Merge Intervals
 *  File      : 57_InsertInterval.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Append newInterval to the existing list, sort by start time, then run
 *  the same greedy one-pass merge as LC 56:
 *    - If next.start <= current.end  →  overlap → extend end = max(end, next.end)
 *    - Else                          →  no overlap → push current, advance
 *
 *  Complexity
 *  ----------
 *  Time  : O(N log N)  – dominated by sort
 *  Space : O(N)        – result vector
 *
 *  Note
 *  ----
 *  An O(N) solution is also possible by skipping all non-overlapping intervals
 *  before the new one, merging the overlapping block, then appending the rest —
 *  but this sort-based approach reuses the LC 56 merge logic cleanly.
 *
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

// ─── Core Solution ───────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
        vector<int>& newInterval) {

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            else
            {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        res.push_back({start, end});

        return res;
    }
};

// ─── Test Harness ────────────────────────────────────────────────────────────

void print_intervals(const vector<vector<int>>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i + 1 < (int)v.size()) cout << ",";
    }
    cout << "]";
}

void run_test(int test_num, vector<vector<int>> intervals,
              vector<int> newInterval, vector<vector<int>> expected) {
    Solution sol;
    vector<vector<int>> result = sol.insert(intervals, newInterval);

    bool pass = (result == expected);
    assert(pass);

    cout << "[" << (pass ? "PASS" : "FAIL") << "] Test " << test_num << " | ";
    cout << "new=[" << newInterval[0] << "," << newInterval[1] << "] into ";
    print_intervals(intervals);   // note: intervals was mutated by insert()
    cout << " -> ";
    print_intervals(result);
    if (!pass) { cout << " (Expected "; print_intervals(expected); cout << ")"; }
    cout << "\n";
}

int main() {
    // Test 1: Classic — new interval overlaps with middle intervals
    run_test(1, {{1,3},{6,9}}, {2,5}, {{1,5},{6,9}});

    // Test 2: New interval merges several existing intervals
    run_test(2, {{1,2},{3,5},{6,7},{8,10},{12,16}}, {4,8}, {{1,2},{3,10},{12,16}});

    // Test 3: Empty intervals list
    run_test(3, {}, {5,7}, {{5,7}});

    // Test 4: New interval goes before all existing intervals
    run_test(4, {{3,5},{6,9}}, {1,2}, {{1,2},{3,5},{6,9}});

    // Test 5: New interval goes after all existing intervals
    run_test(5, {{1,3},{4,6}}, {8,10}, {{1,3},{4,6},{8,10}});

    // Test 6: New interval swallows all existing intervals
    run_test(6, {{1,3},{4,6},{7,9}}, {0,10}, {{0,10}});

    // Test 7: New interval touches boundary (no gap — should merge)
    run_test(7, {{1,5}}, {5,8}, {{1,8}});

    // Test 8: New interval exactly matches an existing interval
    run_test(8, {{1,3},{6,9}}, {6,9}, {{1,3},{6,9}});

    cout << "\n✅  All tests executed.\n";
    return 0;
}
