#include "utils.h"

class Solution {
public:
    int knightDialer(int n) {
        ll dp[n][10];
        fill(dp[0],dp[1],1);
        FOR(i,1,n){
            dp[i][1]=(dp[i-1][6]+dp[i-1][8])%MOD;
            dp[i][2]=(dp[i-1][7]+dp[i-1][9])%MOD;
            dp[i][3]=(dp[i-1][4]+dp[i-1][8])%MOD;
            dp[i][4]=(dp[i-1][3]+dp[i-1][9]+dp[i-1][0])%MOD;
            dp[i][5]=0;
            dp[i][6]=(dp[i-1][1]+dp[i-1][7]+dp[i-1][0])%MOD;
            dp[i][7]=(dp[i-1][2]+dp[i-1][6])%MOD;
            dp[i][8]=(dp[i-1][1]+dp[i-1][3])%MOD;
            dp[i][9]=(dp[i-1][2]+dp[i-1][4])%MOD;
            dp[i][0]=(dp[i-1][4]+dp[i-1][6])%MOD;
        }
        return accumulate(dp[n],dp[n+1],0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.knightDialer(n);
    DBG(ans);

    system("pause");
    return 0;
}
