#include "utils.h"

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        ll dp[d+1][target+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        FOR(i,1,d+1){
            FORR(j,target,1){
                FOR(k,1,f+1){
                    if(j>=k)dp[i][j]+=dp[i-1][j-k];
                }
                dp[i][j]%=MOD;
            }
        }
        return dp[d][target];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int d=2;
    int f=6;
    int target=7;
    auto ans=sol.numRollsToTarget(d,f,target);
    DBG(ans);

    system("pause");
    return 0;
}
