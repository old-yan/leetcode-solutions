#include "utils.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int limit=0;
        for(int a:nums)limit+=a;
        if(limit%2)return false;
        bool dp[limit+1];
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        dp[nums[0]]=true;
        REP(i,nums.size()-1){
            REPR(j,limit){
                if(dp[j]){
                    dp[j+nums[i+1]]=true;
                }
            }
        }
        return dp[limit/2];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,5,11,5};
    auto ans=sol.canPartition(nums);
    DBG(ans);

    system("pause");
    return 0;
}
