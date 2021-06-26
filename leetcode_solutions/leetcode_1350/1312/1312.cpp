#include "utils.h"

class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        REP(i,n){
            REP(j,n-i){
                if(s[j]==s[j+i])dp[j][j+i]=i?dp[j+1][j+i-1]:0;
                else dp[j][j+i]=min(dp[j][j+i-1],dp[j+1][j+i])+1;
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leetcode";
    auto ans=sol.minInsertions(s);
    DBG(ans);

    system("pause");
    return 0;
}
