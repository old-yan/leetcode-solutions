#include "utils.h"

class Solution {
public:
    bool isPalindrome(int x) {
        string s=i2s(x);
        REP(i,s.size()/2)if(s[i]!=s[s.size()-1-i])return false;
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int x=-121;
    auto ans=sol.isPalindrome(x);
    DBG(ans);

    system("pause");
    return 0;
}