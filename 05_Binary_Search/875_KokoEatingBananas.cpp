#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = high;

        while(low <= high)
        {
            int guess = low + (high - low) / 2;
            long long hour = 0;

            for(int i = 0; i < piles.size(); i++)
            {
                hour += piles[i] / guess;

                if(piles[i] % guess != 0)
                    hour++;
            }

            if(hour > h)
                low = guess + 1;
            else
            {
                result = guess;
                high = guess - 1;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: LC example 1
    {
        vector<int> piles = {3,6,7,11};
        int got = sol.minEatingSpeed(piles, 8);
        int exp = 4;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[3,6,7,11]          h=8   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: LC example 2 — only 5 hours, 5 piles → must eat max pile per hour
    {
        vector<int> piles = {30,11,23,4,20};
        int got = sol.minEatingSpeed(piles, 5);
        int exp = 30;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[30,11,23,4,20]     h=5   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: LC example 3 — one extra hour of slack
    {
        vector<int> piles = {30,11,23,4,20};
        int got = sol.minEatingSpeed(piles, 6);
        int exp = 23;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[30,11,23,4,20]     h=6   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: single pile, h == 1 → must eat entire pile
    {
        vector<int> piles = {5};
        int got = sol.minEatingSpeed(piles, 1);
        int exp = 5;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[5]                 h=1   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: single large pile, h gives slack → speed can halve
    {
        vector<int> piles = {10};
        int got = sol.minEatingSpeed(piles, 5);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[10]                h=5   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: all piles size 1, h == n → speed = 1
    {
        vector<int> piles = {1,1,1,1};
        int got = sol.minEatingSpeed(piles, 4);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[1,1,1,1]           h=4   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: h much larger than needed → minimum possible speed = 1
    {
        vector<int> piles = {3,6,7,11};
        int got = sol.minEatingSpeed(piles, 100);
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[3,6,7,11]          h=100 expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: large single pile — LC constraint edge case
    {
        vector<int> piles = {312884470};
        int got = sol.minEatingSpeed(piles, 312884469);
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]")
             << "  piles=[312884470]         h=312884469  expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
