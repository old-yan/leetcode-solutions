#include "utils.h"

class Solution {
public:
    int numTilings(int N) {
        ll dp[N][2];
        dp[0][0]=1;
        dp[0][1]=0;
        FOR(i,1,N){
            dp[i][0]=i>1?(dp[i-1][0]+dp[i-1][1]*2+dp[i-2][0])%MOD:2;
            dp[i][1]=i>1?(dp[i-1][1]+dp[i-2][0])%MOD:1;
        }
        return dp[N-1][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=5;
    auto ans=sol.numTilings(N);
    DBG(ans);

    system("pause");
    return 0;
}
