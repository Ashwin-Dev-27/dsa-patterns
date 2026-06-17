#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        int min_ending = nums[0];
        int max_ending = nums[0];
        int result = nums[0];

        for(i =1; i<n; i++)
        {
            int v1 = nums[i];
            int v2 = min_ending * nums[i];
            int v3 = max_ending * nums[i];

            max_ending = max(v1,max(v2,v3));
            min_ending = min(v1,min(v2,v3));
            result = max(result,max(max_ending,min_ending));
        }
        return result;
    }
};

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.maxProduct(nums);
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
    
    cout << "-> max product = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {2, 3, -2, 4}, 6);
    run_test(2, {-2, 0, -1}, 0);
    run_test(3, {-2, 3, -4}, 24);
    run_test(4, {0, 2}, 2);
    run_test(5, {-2}, -2);
    run_test(6, {-2, -3, 7}, 42);
    
    cout << "\n✅  All tests executed.\n";
    return 0;
}
