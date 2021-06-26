#include "utils.h"

class Solution {
public:
    int massage(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1][2];
        dp[n][0]=dp[n][1]=0;
        REPR(i,n-1){
            dp[i][0]=dp[i+1][1];
            dp[i][1]=max(dp[i][0],nums[i]+dp[i+1][0]);
        }
        return dp[0][1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,1};
    auto ans=sol.massage(nums);
    DBG(ans);

    system("pause");
    return 0;
}
