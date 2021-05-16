#include "utils.h"

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n=jobs.size();
        int sum[1<<n];
        sum[0]=0;
        FOR(state,1,1<<n){
            sum[state]=sum[state-(1<<__builtin_ctz(state))]+jobs[__builtin_ctz(state)];
        }
        int dp[1<<n];
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        REP(i,k){
            FORR(state,(1<<n)-1,1){
                for(int s=state;s;s=(s-1)&state){
                    chmin(dp[state],max(dp[state-s],sum[s]));
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

    vi jobs{3,2,3};
    int k=3;
    auto ans=sol.minimumTimeRequired(jobs,k);
    DBG(ans);

    system("pause");
    return 0;
}
