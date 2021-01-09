#include "utils.h"

class Solution {
public:
    int longestPalindrome(string s) {
        int num[128]={0};
        for(char c:s){
            num[c]++;
        }
        int ans=0;
        REP(i,128){
            if(num[i])ans+=num[i]-num[i]%2;
        }
        if(ans<s.size())ans++;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abccccdd";
    auto ans=sol.longestPalindrome(s);
    DBG(ans);

    system("pause");
    return 0;
}
