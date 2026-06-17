#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        int i = 0;
        int n = a.size();
        int ans = a[0];
        int best_ending = a[0];

        for(i =1; i<n; i++)
        {
            int v1 = best_ending + a[i];
            int v2 = a[i];
            best_ending = min(v1,v2);
            ans = min(ans,best_ending);
        }
        return ans;
        
    }
};

void run_test(int test_num, vector<int> a, int expected) {
    Solution sol;
    int result = sol.smallestSumSubarray(a);
    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";
    
    // Print input array up to 5 elements for brevity
    cout << "[";
    for(int i=0; i < min((int)a.size(), 5); ++i) {
        cout << a[i] << (i == min((int)a.size(), 5)-1 ? "" : ",");
    }
    if (a.size() > 5) cout << ",...";
    cout << "] ";
    
    cout << "-> min sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {3, -4, 2, -3, -1, 7, -5}, -6);
    run_test(2, {2, 6, 8, 1, 4}, 1);
    run_test(3, {-2, -3, -4, -1}, -10);
    run_test(4, {-1, -2, -3, -4}, -10);
    run_test(5, {1}, 1);
    run_test(6, {5, 4, -1, 7, 8}, -1);
    
    cout << "\n✅  All tests executed.\n";
    return 0;
}
