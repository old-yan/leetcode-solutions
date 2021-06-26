#include "utils.h"

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss=s.substr(1,s.size()-1)+s.substr(0,s.size()-1);
        return int(ss.find(s))>=0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcabcabcabc";
    auto ans=sol.repeatedSubstringPattern(s);
    DBG(ans);

    system("pause");
    return 0;
}
