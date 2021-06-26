#include "utils.h"

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        ll dp[n][k+1];
        memset(dp,0,sizeof(dp));
        dp[n-1][1]=0;
        REPR(i,n-2){
            FOR(j,1,k+1){
                dp[i][j]=(dp[i+1][j-1]+dp[i+1][j]*(n-1-i))%MOD;
            }
        }
        return dp[0][k];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    int k=2;
    auto ans=sol.rearrangeSticks(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
