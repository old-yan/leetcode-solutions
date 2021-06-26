#include "utils.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ll dp[2][nums.size()];
        memset(dp,0,sizeof(dp));
        ll ans=INT_MIN;
        REP(i,nums.size()){
            if(!i){
                dp[0][i]=dp[1][i]=nums[0];
            }
            else if(nums[i]){
                if(nums[i]>0){
                    dp[0][i]=min(ll(nums[i]),dp[0][i-1]*nums[i]);
                    dp[1][i]=max(ll(nums[i]),dp[1][i-1]*nums[i]);
                }
                else{
                    dp[0][i]=min(ll(nums[i]),dp[1][i-1]*nums[i]);
                    dp[1][i]=max(ll(nums[i]),dp[0][i-1]*nums[i]);
                }
            }
            chmax(ans,dp[1][i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,-2,4};
    auto ans=sol.maxProduct(nums);
    DBG(ans);

    system("pause");
    return 0;
}
