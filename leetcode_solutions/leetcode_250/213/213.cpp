#include "utils.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int dp[nums.size()][2];
        REP(i,nums.size()){
            if(!i){
                dp[i][0]=0;
                dp[i][1]=nums[0];
            }
            else{
                dp[i][0]=max(dp[i-1][0],nums[i]);
                if(i>1)chmax(dp[i][0],dp[i-2][0]+nums[i]);
                dp[i][1]=max(dp[i-1][1],nums[i]);
                if(i>1)chmax(dp[i][1],dp[i-2][1]+nums[i]);
            }
        }
        return max(dp[nums.size()-1][0],dp[nums.size()-2][1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,1};
    auto ans=sol.rob(nums);
    DBG(ans);

    system("pause");
    return 0;
}
