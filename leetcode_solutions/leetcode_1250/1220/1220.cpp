#include "utils.h"

class Solution {
public:
    int countVowelPermutation(int n) {
        ll dp[n][5];
        REP(j,5){
            dp[0][j]=1;
        }
        FOR(i,1,n){
            dp[i][0]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%MOD;
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%MOD;
            dp[i][2]=(dp[i-1][1]+dp[i-1][3])%MOD;
            dp[i][3]=dp[i-1][2];
            dp[i][4]=(dp[i-1][2]+dp[i-1][3])%MOD;
        }
        return accumulate(dp[n-1],dp[n],0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.countVowelPermutation(n);
    DBG(ans);

    system("pause");
    return 0;
}
