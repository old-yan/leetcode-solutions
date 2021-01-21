#include "utils.h"

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        ll dp[m][n][N+1];
        memset(dp,0,sizeof(dp));
        ll ans=0;
        FOR(step,1,N+1){
            REP(i,m){
                REP(j,n){
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(ii>=0&&ii<m&&jj>=0&&jj<n){
                            dp[i][j][step]+=dp[ii][jj][step-1];
                        }
                        else if(step==1)dp[i][j][step]++;
                    }
                    dp[i][j][step]%=MOD;
                }
            }
            ans+=dp[i][j][step];
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=2;
    int n=2;
    int N=2;
    int i=0;
    int j=0;
    auto ans=sol.findPaths(m,n,N,i,j);
    DBG(ans);

    system("pause");
    return 0;
}
