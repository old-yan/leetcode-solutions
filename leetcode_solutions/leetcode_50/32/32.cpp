#include "utils.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size()+1];
        #define dp(x) (x<0?0:dp[x]) 
        int ans=0;
        REP(i,s.size()){
            if(s[i]=='(')dp[i]=0;
            else{
                if(i-1>=0&&s[i-1]=='(')dp[i]=dp(i-2)+2;
                else if(i-1-dp(i-1)>=0&&s[i-1-dp(i-1)]=='(')dp[i]=dp(i-1)+2+dp(i-1-dp(i-1)-1);
                else dp[i]=0;
            }
            chmax(ans,dp[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="()(())";
    auto ans=sol.longestValidParentheses(s);
    DBG(ans);

    system("pause");
    return 0;
}
