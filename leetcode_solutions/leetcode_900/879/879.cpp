#include "utils.h"

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        int dp[n+1][minProfit+1];
        memset(dp,0,sizeof(dp));
        dp[n][0]=1;
        REP(i,m){
            REP(j,n+1-group[i]){
                REP(k,minProfit+1){
                    if(k<minProfit-profit[i]){
                        dp[j][k+profit[i]]=(dp[j][k+profit[i]]+dp[j+group[i]][k])%MOD;
                    }
                    else{
                        dp[j][minProfit]=(dp[j][minProfit]+dp[j+group[i]][k])%MOD;
                    }
                }
            }
        }
        ll ans=0;
        REP(j,n+1)ans=(ans+dp[j][minProfit])%MOD;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    int minProfit=5;
    vi group{2,3,5};
    vi profit{6,7,8};
    auto ans=sol.profitableSchemes(n,minProfit,group,profit);
    DBG(ans);

    system("pause");
    return 0;
}
