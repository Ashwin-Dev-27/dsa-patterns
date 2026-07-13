#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        for(int i = 0; i<text.size();i++)
        have[text[i]]++;
        unordered_map<char,int>need;

        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;
        
        int result = INT_MAX;
        for(auto i:need)
        {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            int times = fhave/fneed;
            result = min(result,times);
        }
        return result;
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: standard LC example
    {
        int got = sol.maxNumberOfBalloons("nlaebolko");
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"nlaebolko\"           expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: two balloons
    {
        int got = sol.maxNumberOfBalloons("loonbalxpoonball");
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"loonbalxpoonball\"   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: no balloon possible
    {
        int got = sol.maxNumberOfBalloons("leetcode");
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"leetcode\"           expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: exactly one balloon
    {
        int got = sol.maxNumberOfBalloons("balloon");
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"balloon\"            expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: two exact balloons
    {
        int got = sol.maxNumberOfBalloons("balloonballoon");
        int exp = 2;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"balloonballoon\"     expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: missing 'o' and 'n'
    {
        int got = sol.maxNumberOfBalloons("bbaall");
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"bbaall\"             expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: extra letters, limited by 'a'
    {
        int got = sol.maxNumberOfBalloons("bbballlloonnn");
        int exp = 1;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"bbballlloonnn\"      expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: empty string
    {
        int got = sol.maxNumberOfBalloons("");
        int exp = 0;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  text=\"\"                   expected=" << exp << "  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
