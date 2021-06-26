#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        ll dp[prices.size()][2];
        REP(i,prices.size()){
            if(!i){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
            }
            else{
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
                dp[i][1]=dp[i-1][1];
                if(i==1)chmax(dp[i][1],(ll)-prices[i]);
                else if(i>1)chmax(dp[i][1],dp[i-2][0]-prices[i]);
            }
        }
        return dp[prices.size()-1][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi prices{1,2,3,0,2};
    auto ans=sol.maxProfit(prices);
    DBG(ans);

    system("pause");
    return 0;
}
