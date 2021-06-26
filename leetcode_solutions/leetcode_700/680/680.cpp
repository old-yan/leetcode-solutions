#include "utils.h"

class Solution {
public:
    bool validPalindrome(string s) {
        vi arm=getarm(s);
        int i,j;
        for(i=0,j=s.size()-1;i<j&&s[i]==s[j];i++,j--);
        if(i>=j)return true;
        return query_polindromic(arm,i,j-1)||query_polindromic(arm,i+1,j);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abca";
    auto ans=sol.validPalindrome(s);
    DBG(ans);

    system("pause");
    return 0;
}
