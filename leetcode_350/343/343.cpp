#include "utils.h"

class Solution {
public:
    int integerBreak(int n) {
        if(n<4)return n-1;
        ll dp[n+1];
        memset(dp,0,sizeof(dp));
        iota(dp,dp+4,0);
        FOR(i,4,n+1){
            FOR(j,2,i){
                chmax(dp[i],dp[i-j]*j);
            }
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=8;
    auto ans=sol.integerBreak(n);
    DBG(ans);

    system("pause");
    return 0;
}
