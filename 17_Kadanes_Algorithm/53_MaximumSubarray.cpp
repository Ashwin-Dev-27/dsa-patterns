#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int ans = nums[0];
        int best_ending = nums[0];

        for(i =1; i<n; i++)
        {
            int v1 = best_ending + nums[i];
            int v2 = nums[i];
            best_ending = max(v1,v2);
            ans = max(ans,best_ending);
        }
        return ans;
    }
};

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maxSubArray(nums);
    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";
    
    // Print input array up to 5 elements for brevity
    cout << "[";
    for(int i=0; i < min((int)nums.size(), 5); ++i) {
        cout << nums[i] << (i == min((int)nums.size(), 5)-1 ? "" : ",");
    }
    if (nums.size() > 5) cout << ",...";
    cout << "] ";
    
    cout << "-> max sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {-2,1,-3,4,-1,2,1,-5,4}, 6);
    run_test(2, {1}, 1);
    run_test(3, {5,4,-1,7,8}, 23);
    run_test(4, {-1}, -1);
    run_test(5, {-2,-1}, -1);
    run_test(6, {-5,-4,-1,-7,-8}, -1);
    
    cout << "\n✅  All tests executed.\n";
    return 0;
}
