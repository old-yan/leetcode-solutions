#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n)return 0;
        int dp[2][n];
        REP(i,n){
            if(!i){
                dp[0][i]=0;
                dp[1][i]=-prices[i];
            }
            else{
                dp[0][i]=max(dp[0][i-1],dp[1][i-1]+prices[i]);
                dp[1][i]=max(dp[1][i-1],dp[0][i-1]-prices[i]);
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi prices{7,1,5,3,6,4};
    auto ans=sol.maxProfit(prices);
    DBG(ans);

    system("pause");
    return 0;
}
