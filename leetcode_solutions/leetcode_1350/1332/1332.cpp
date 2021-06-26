#include "utils.h"

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty())return 0;
        else if(isPalindromic(ALL(s)))return 1;
        else return 2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ababa";
    auto ans=sol.removePalindromeSub(s);
    DBG(ans);

    system("pause");
    return 0;
}
