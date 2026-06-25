/*
 * ============================================================================
 *  Problem   : Merge Intervals  (LeetCode #56)
 *  Pattern   : Merge Intervals
 *  File      : 56_MergeIntervals.cpp
 * ============================================================================
 *
 *  Approach
 *  --------
 *  Sort intervals by start time.
 *  Track the current interval's [start_1, end_1].
 *  For each next interval [start_2, end_2]:
 *    - If end_1 >= start_2 → overlap → extend end_1 = max(end_1, end_2)
 *    - Else → no overlap → push current to result, move to next interval
 *  After the loop, push the last tracked interval.
 *
 *  Complexity
 *  ----------
 *  Time  : O(N log N)  – dominated by sort
 *  Space : O(N)        – result vector
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int start_1 = intervals[0][0];
        int end_1 = intervals[0][1];

        for(int i =1; i<n; i++)
        {
            int start_2 = intervals[i][0];
            int end_2 = intervals[i][1];
            if(end_1>=start_2)
            {
                end_1 = max(end_1,end_2);
            }
            else
            {
                res.push_back({start_1,end_1});
                start_1 = start_2;
                end_1 = end_2;         
            }
        }
        res.push_back({start_1,end_1});
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

void run_test(int test_num, vector<vector<int>> intervals, vector<vector<int>> expected) {
    Solution sol;
    vector<vector<int>> result = sol.merge(intervals);

    bool pass = (result == expected);
    assert(pass);

    cout << "[" << (pass ? "PASS" : "FAIL") << "] Test " << test_num << " | ";
    print_intervals(intervals);
    cout << " -> ";
    print_intervals(result);
    if (!pass) { cout << " (Expected "; print_intervals(expected); cout << ")"; }
    cout << "\n";
}

int main() {
    // Test 1: Standard overlap — classic example
    run_test(1, {{1,3},{2,6},{8,10},{15,18}}, {{1,6},{8,10},{15,18}});

    // Test 2: All merge into one
    run_test(2, {{1,4},{4,5}}, {{1,5}});

    // Test 3: No overlaps at all
    run_test(3, {{1,2},{3,4},{5,6}}, {{1,2},{3,4},{5,6}});

    // Test 4: Single interval
    run_test(4, {{5,10}}, {{5,10}});

    // Test 5: All intervals overlap into one
    run_test(5, {{1,10},{2,5},{3,8}}, {{1,10}});

    // Test 6: Unsorted input — must sort first
    run_test(6, {{15,18},{1,3},{2,6},{8,10}}, {{1,6},{8,10},{15,18}});

    // Test 7: Adjacent but not overlapping (touch at boundary)
    run_test(7, {{1,2},{2,3},{3,4}}, {{1,4}});

    // Test 8: Two non-overlapping intervals
    run_test(8, {{1,5},{6,10}}, {{1,5},{6,10}});

    cout << "\n✅  All tests executed.\n";
    return 0;
}
