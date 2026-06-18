#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int left = 0;
        int right;
        for(int i=0; i<n; i++)
        {
            sum = sum + nums[i];
        }    
        for(int i =0; i<n; i++)
        {
            right = sum - nums[i]-left;
            if(left == right)
            return i;
            left = left + nums[i];
        }
        return -1;
    }
};

void run_test(int test_num, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.pivotIndex(nums);
    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";

    cout << "[";
    for(int i=0; i < min((int)nums.size(), 5); ++i) {
        cout << nums[i] << (i == min((int)nums.size(), 5)-1 ? "" : ",");
    }
    if (nums.size() > 5) cout << ",...";
    cout << "] ";

    cout << "-> pivot = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {1,7,3,6,5,6}, 3);
    run_test(2, {1,2,3}, -1);
    run_test(3, {2,1,-1}, 0);
    run_test(4, {0,0,0,0}, 0);
    run_test(5, {1}, 0);
    run_test(6, {}, -1);
    run_test(7, {-1,-1,-1,-1,-1}, 2);
    run_test(8, {-7,1,5,2,-4,3,0}, 3);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
