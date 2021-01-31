#include "utils.h"

class Solution {
public:
    int kInversePairs(int n, int k) {
        ll dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        #define a(i,j) (j<0?0:dp[i][j])
        REP(i,n+1){
            REP(j,k+1){
                if(i)dp[i][j]=(a(i,j-1)+dp[i-1][j]-a(i-1,j-i)+MOD)%MOD;
                else dp[i][j]=1;
            }
        }
        return (dp[n][k]-a(n,k-1)+MOD)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    int k=1;
    auto ans=sol.kInversePairs(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
