#include "utils.h"

class Solution {
public:
    int maxCoins(vector<int>&nums) {
        int n=nums.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        #define nums(i) (i>=0&&i<n?nums[i]:1)
        #define dp(i,j) (i<=j?dp[i][j]:0)
        REP(l,n){
            REP(i,n-l){
                FOR(j,i,i+l+1){
                    chmax(dp[i][i+l],nums(j)*nums(i-1)*nums(i+l+1)+dp(i,j-1)+dp(j+1,i+l));
                }
            }
        }
        return dp[0][n-1];
    }
};



int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,1,5,8};
    auto ans=sol.maxCoins(nums);
    DBG(ans);

    system("pause");
    return 0;
}
