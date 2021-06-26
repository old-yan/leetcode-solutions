#include "utils.h"

class Solution {
public:
    //本题一看数据，挺大，那么就得考虑动态规划
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        //第一个维度，i 表示当前下标为i
        //第二个维度，表示子序列长度奇偶性，0为偶，1为奇
        //第三个维度，表示子序列的最值，0为最小值，1为最大值
        //dp[i][0][0]表示到i为止偶数长度的最小值
        //dp[i][0][1]表示到i为止偶数长度的最大值
        //dp[i][1][0]表示到i为止奇数长度的最小值
        //dp[i][1][1]表示到i为止奇数长度的最大值
        ll _dp[n+1][2][2];
        auto dp=_dp+1;
        //初值
        dp[-1][0][0]=dp[-1][0][1]=0;
        dp[-1][1][0]=INT_MAX;dp[-1][1][1]=INT_MIN;
        //从前往后转移
        for(int i=0;i<n;i++){
            dp[i][0][0]=min(dp[i-1][0][0],(ll)-nums[i]+dp[i-1][1][0]);
            dp[i][0][1]=max(dp[i-1][0][1],(ll)-nums[i]+dp[i-1][1][1]);
            dp[i][1][0]=min(dp[i-1][1][0],(ll)nums[i]+dp[i-1][0][0]);
            dp[i][1][1]=max(dp[i-1][1][1],(ll)nums[i]+dp[i-1][0][1]);
        }
        return max(dp[n-1][0][1],dp[n-1][1][1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,2,5,3};
    auto ans=sol.maxAlternatingSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
