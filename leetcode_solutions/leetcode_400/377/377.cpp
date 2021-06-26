#include "utils.h"

class Solution {
public:
    int combinationSum4(vector<int>&nums, int target) {
        if(nums.empty())return 0;
        sort(ALL(nums));
        while(nums.size()&&nums.back()>target)nums.pop_back();
        ll dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        FOR(i,1,target+1){
            for(int a:nums){
                if(a>i)break;
                dp[i]=(dp[i]+dp[i-a])%INT_MAX;
            }
        }
        return dp[target];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    int target=4;
    auto ans=sol.combinationSum4(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}
