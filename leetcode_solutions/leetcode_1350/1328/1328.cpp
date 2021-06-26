#include "utils.h"

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()<2)return "";
        REP(i,palindrome.size()/2){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome.back()='b';
        return palindrome;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string palindrome="abccba";
    auto ans=sol.breakPalindrome(palindrome);
    DBG(ans);

    system("pause");
    return 0;
}
