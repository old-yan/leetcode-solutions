#include "utils.h"

vvi table=combinationTable(200,5);
class Solution {
public:
    int keyboard(int k, int n) {
        int dp[27][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        FOR(i,1,27){
            REP(j,n+1){
                REP(cur,k+1)if(j-cur>=0){
                    dp[i][j]=(dp[i][j]+(ll)dp[i-1][j-cur]*table[j][cur])%MOD;
                }
            }
        }
        return dp[26][n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=1;
    int n=1;
    auto ans=sol.keyboard(k,n);
    DBG(ans);

    system("pause");
    return 0;
}
