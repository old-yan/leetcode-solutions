#include "utils.h"

class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        vi can[41];
        REP(i,n){
            for(int h:hats[i])can[h].pb(i);
        }
        int dp[1<<n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        FOR(h,1,41){
            REPR(i,(1<<n)-1){
                for(int j:can[h]){
                    if(i>>j&1){
                        dp[i]=(dp[i]+dp[i-(1<<j)])%MOD;
                    }
                }
            }
        }
        return dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi hats=makevvi("[[3,4],[4,5],[5]]");
    auto ans=sol.numberWays(hats);
    DBG(ans);

    system("pause");
    return 0;
}
