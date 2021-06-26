#include "utils.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        FOR(i,1,n1+1){
            FOR(j,1,n2+1){
                if(text1[i-1]==text2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n1][n2];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text1="abcde";
    string text2="ace";
    auto ans=sol.longestCommonSubsequence(text1,text2);
    DBG(ans);

    system("pause");
    return 0;
}
