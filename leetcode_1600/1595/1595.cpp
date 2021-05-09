#include "utils.h"

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m=cost.size(),n=cost[0].size();
        int dp[1<<n];
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        REP(i,m){
            static int sum[4096];
            sum[0]=0;
            FOR(j,1,1<<n)sum[j]=sum[j-(1<<__builtin_ctz(j))]+cost[i][__builtin_ctz(j)];
            REPR(j,(1<<n)-1){
                dp[j]=0x3f3f3f3f;
                for(int s=j;s;s=(s-1)&j){
                    chmin(dp[j],dp[j-s]+sum[s]);
                }
                for(int t=(1<<n)-1-j,s=t;s;s=(s-1)&t){
                    chmin(dp[j],dp[j+s]);
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

    vvi cost=makevvi("[[1, 3, 5], [4, 1, 1], [1, 5, 3]]");
    auto ans=sol.connectTwoGroups(cost);
    DBG(ans);

    system("pause");
    return 0;
}
