#include "utils.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        vi arm=getarm(s);
        int maxmiddle;
        REP(i,arm.size()){
            if(i-arm[i]==1)maxmiddle=i;
        }
        string prefix=s.substr(maxmiddle-1,s.size()-maxmiddle+1);
        reverse(ALL(prefix));
        return prefix+s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aacecaaa";
    auto ans=sol.shortestPalindrome(s);
    DBG(ans);

    system("pause");
    return 0;
}
