#include "utils.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        REP(i,n){
            REP(j,n-i){
                if(!i)dp[j][j+i]=1;
                else{
                    if(s[j]==s[j+i])dp[j][j+i]=dp[j+1][j+i-1]+2;
                    else dp[j][j+i]=max(dp[j][j+i-1],dp[j+1][j+i]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="bbbab";
    auto ans=sol.longestPalindromeSubseq(s);
    DBG(ans);

    system("pause");
    return 0;
}
