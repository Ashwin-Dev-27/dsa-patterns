#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool fun(unordered_map<char,int>have,unordered_map<char,int>need)
    {
        for(auto i :need)
        {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if(fhave<fneed)
            return false;
        }
        return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        for(int i =0; i<ransomNote.size(); i++)
        {
            need[ransomNote[i]]++;
        }
        for(int i =0; i<magazine.size(); i++)
        {
            have[magazine[i]]++;
        }
        return fun(have,need);
    }
};

int main() {
    Solution sol;
    int pass = 0, total = 8;

    // Test 1: single char not available
    {
        bool got = sol.canConstruct("a", "b");
        bool exp = false;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"a\"  magazine=\"b\"  expected=0  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 2: more needed than available
    {
        bool got = sol.canConstruct("aa", "ab");
        bool exp = false;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"aa\" magazine=\"ab\"  expected=0  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 3: enough chars in magazine
    {
        bool got = sol.canConstruct("aa", "aab");
        bool exp = true;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"aa\" magazine=\"aab\" expected=1  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 4: completely different chars
    {
        bool got = sol.canConstruct("abc", "def");
        bool exp = false;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"abc\" magazine=\"def\" expected=0  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 5: enough duplicates
    {
        bool got = sol.canConstruct("abc", "aabbcc");
        bool exp = true;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"abc\" magazine=\"aabbcc\" expected=1  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 6: three needed, two available
    {
        bool got = sol.canConstruct("aaa", "aa");
        bool exp = false;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"aaa\" magazine=\"aa\"  expected=0  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 7: empty ransomNote
    {
        bool got = sol.canConstruct("", "anything");
        bool exp = true;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"\" magazine=\"anything\" expected=1  got=" << got << endl;
        if (got == exp) pass++;
    }
    // Test 8: same chars, different order
    {
        bool got = sol.canConstruct("aab", "baa");
        bool exp = true;
        cout << (got == exp ? "[PASS]" : "[FAIL]") << "  ransomNote=\"aab\" magazine=\"baa\"  expected=1  got=" << got << endl;
        if (got == exp) pass++;
    }

    cout << "\n" << pass << "/" << total << " tests passed." << endl;
    return 0;
}
