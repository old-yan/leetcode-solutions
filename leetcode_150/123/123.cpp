#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n)return 0;
        int dp[2][2][n];
        REP(i,n){
            if(!i){
                dp[0][0][i]=-INF;
                dp[0][1][i]=-prices[i];
                dp[1][0][i]=-INF;
                dp[1][1][i]=-INF;
            }
            else{
                dp[0][0][i]=max(dp[0][0][i-1],dp[0][1][i-1]+prices[i]);
                dp[0][1][i]=max(dp[0][1][i-1],-prices[i]);
                dp[1][0][i]=max(dp[1][0][i-1],dp[1][1][i-1]+prices[i]);
                dp[1][1][i]=max(dp[1][1][i-1],dp[0][0][i-1]-prices[i]);
            }
        }
        return max(max(0,dp[1][0][n-1]),dp[0][0][n-1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi prices{3,3,5,0,0,3,1,4};
    auto ans=sol.maxProfit(prices);
    DBG(ans);

    system("pause");
    return 0;
}
