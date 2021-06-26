#include "utils.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        int dp[nums.size()][2];
        REP(i,nums.size()){
            if(!i){
                dp[i][0]=0;
                dp[i][1]=nums[i];
            }
            else{
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
                dp[i][1]=dp[i-1][0]+nums[i];
            }
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-1][1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,7,9,3,1};
    auto ans=sol.rob(nums);
    DBG(ans);

    system("pause");
    return 0;
}
