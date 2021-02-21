#include "utils.h"

class Solution {
public:
    //本题可以使用动态规划，根据以后的收益，决定当前的最佳选择
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(),m=multipliers.size();
        long ans=0;
        long cur=0;
        //dp[i][j]表示当面临multipliers[i]，且nums剩余区间以j开头时，可获取的最大收益
        //毫无疑问j<=i，因为即使每次都从nums前面取，临界情况也是j==i，何况有时候会从后面取。
        //而nums的具体区间为[j,j+n-i-1]
        long dp[m+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=m-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                //从后取or从前取，选最大
                dp[i][j]=max(dp[i+1][j]+long(multipliers[i])*nums[j+n-i-1],dp[i+1][j+1]+long(multipliers[i])*nums[j]);
                if(!i)ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
