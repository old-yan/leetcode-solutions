#include "utils.h"

class Solution {
public:
    int numOfArrays(int n, int m, int K) {
        ll dp[K+1][n+1][m+1];
        memset(dp,0,sizeof(dp));
        #define a(k,i,j) dp[k][i+1][j]
        a(0,-1,0)=1;
        partial_sum(dp[0][0],dp[0][1],dp[0][0]);
        FOR(k,1,K+1){
            REP(i,n){
                FOR(j,1,m+1){
                    a(k,i,j)=(a(k,i-1,j)*j+a(k-1,i-1,j-1))%MOD;
                }
            }
            REP(i,n){
                partial_sum(dp[k][i+1],dp[k][i+2],dp[k][i+1]);
            }
        }
        return a(K,n-1,m)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    int m=3;
    int k=1;
    auto ans=sol.numOfArrays(n,m,k);
    DBG(ans);

    system("pause");
    return 0;
}
