#include "utils.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n];
        #define a(i) (i>=0?dp[i]:0)
        REP(i,n){
            dp[i]=min(a(i-2),a(i-1))+cost[i];
        }
        return min(dp[n-2],dp[n-1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    auto ans=sol.minCostClimbingStairs(cost);
    DBG(ans);

    system("pause");
    return 0;
}
