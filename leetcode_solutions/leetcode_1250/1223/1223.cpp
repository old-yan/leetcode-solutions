#include "utils.h"

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        ll dp[n][6][16];
        memset(dp,0,sizeof(dp));
        REP(j,6){
            dp[0][j][0]=dp[0][j][1]=1;
        }
        ll pre=6;
        FOR(i,1,n){
            ll cur=0;
            REP(j,6){
                dp[i][j][0]=dp[i][j][1]=(pre-dp[i-1][j][0]+MOD)%MOD;
                FOR(k,2,rollMax[j]+1){
                    dp[i][j][k]=dp[i-1][j][k-1];
                    dp[i][j][0]=(dp[i][j][0]+dp[i][j][k])%MOD;
                }
                cur=(cur+dp[i][j][0])%MOD;
            }
            pre=cur;
        }
        return pre;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    vi rollMax{1,1,2,2,2,3};
    auto ans=sol.dieSimulator(n,rollMax);
    DBG(ans);

    system("pause");
    return 0;
}
