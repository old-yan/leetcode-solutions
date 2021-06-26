#include "utils.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<2||!k)return 0;
        chmin(k,n/2);
        ll dp[n][k][2];
        ll ans=0;
        REP(i,n){
            if(!i){
                REP(j,k){
                    dp[i][j][0]=dp[i][j][1]=INT_MIN;
                }
                dp[i][0][1]=-prices[i];
            }
            else{
                REP(j,k){
                    dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                    if(j)dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
                    else dp[i][j][1]=max(dp[i-1][j][1],(ll)-prices[i]);
                    chmax(ans,dp[i][j][0]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k = 2;
    vi prices{3,2,6,5,0,3};
    auto ans=sol.maxProfit(k,prices);
    DBG(ans);

    system("pause");
    return 0;
}
