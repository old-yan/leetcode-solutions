#include "utils.h"

class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        if(!n)return 0;
        int dp[n+1][n];
        memset(dp,0,sizeof(dp));
        REP(i,n){
            REP(j,n-i){
                dp[j][j+i]=dp[j+1][j+i]+1;
                FOR(split,j+1,j+i+1){
                    if(s[split]==s[j])chmin(dp[j][j+i],dp[j][split-1]+dp[split+1][j+i]);
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

    string s="abc";
    auto ans=sol.strangePrinter(s);
    DBG(ans);

    system("pause");
    return 0;
}
