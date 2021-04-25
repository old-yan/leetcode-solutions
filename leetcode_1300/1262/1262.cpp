#include "utils.h"

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        ll dp[n+1][3];
        dp[0][0]=0;
        dp[0][1]=dp[0][2]=INT_MIN;
        REP(i,n){
            REP(j,3){
                dp[i+1][(j+nums[i])%3]=max(dp[i][(j+nums[i])%3],dp[i][j]+nums[i]);
            }
        }
        return dp[n][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,4};
    auto ans=sol.maxSumDivThree(nums);
    DBG(ans);

    system("pause");
    return 0;
}
