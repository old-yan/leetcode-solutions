#include "utils.h"

class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(char c:s){
            if(isalpha(c)||isdigit(c)){
                ss+=tolower(c);
            }
        }
        REP(i,ss.size()/2){
            if(ss[i]!=ss[ss.size()-1-i])return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="A man, a plan, a canal: Panama";
    auto ans=sol.isPalindrome(s);
    DBG(ans);

    system("pause");
    return 0;
}
