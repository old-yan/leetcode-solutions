#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp[prices.size()][2];
        REP(i,prices.size()){
            if(!i){
                dp[i][0]=0;
                dp[i][1]=-prices[i]-fee;
            }
            else{
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
            }
        }
        return dp[prices.size()][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi prices{1, 3, 2, 8, 4, 9};
    int fee=2;
    auto ans=sol.maxProfit(prices,fee);
    DBG(ans);

    system("pause");
    return 0;
}
