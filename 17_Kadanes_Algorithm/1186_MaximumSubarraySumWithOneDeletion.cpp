#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int v2;
        int no_delete = arr[0];
        int one_delete = INT_MIN;
        int result = arr[0];

        for(int i = 1; i<n; i++)
        {
            int prev_no_delete = no_delete;
            int prev_one_delete = one_delete;
            no_delete = max(arr[i], prev_no_delete + arr[i]);

            if(prev_one_delete == INT_MIN)
            v2=arr[i];
            else
            v2=prev_one_delete +arr[i];
            one_delete = max(v2,prev_no_delete);
            result = max(result,max(one_delete,no_delete));
        }
        return result;
    }
};

void run_test(int test_num, vector<int> arr, int expected) {
    Solution sol;
    int result = sol.maximumSum(arr);
    cout << "[";
    if (result == expected) cout << "PASS";
    else cout << "FAIL";
    cout << "] Test " << test_num << " | ";

    cout << "[";
    for(int i=0; i < min((int)arr.size(), 5); ++i) {
        cout << arr[i] << (i == min((int)arr.size(), 5)-1 ? "" : ",");
    }
    if (arr.size() > 5) cout << ",...";
    cout << "] ";

    cout << "-> max sum = " << result;
    if (result != expected) cout << " (Expected " << expected << ")";
    cout << "\n";
}

int main() {
    run_test(1, {1,-2,0,3}, 4);
    run_test(2, {1,-2,-2,3}, 3);
    run_test(3, {-1,-1,-1,-1}, -1);
    run_test(4, {10,-20,30}, 40);
    run_test(5, {0}, 0);
    run_test(6, {-1,2,3,-4,5}, 10);
    run_test(7, {-1,-2}, -1);
    run_test(8, {-2}, -2);

    cout << "\n✅  All tests executed.\n";
    return 0;
}
