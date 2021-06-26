#include "utils.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        int num[128]={0};
        for(char c:s)num[c]++;
        for(char c:t)num[c]--;
        REP(i,128)if(num[i])return false;
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="anagram";
    string t="nagaram";
    auto ans=sol.isAnagram(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
