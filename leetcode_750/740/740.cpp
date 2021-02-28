#include "utils.h"

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        ll count[10001]={0};
        for(int a:nums)count[a]++;
        ll dp[10001]={0};
        dp[1]=count[1];
        FOR(i,2,10001){
            dp[i]=max(dp[i-1],dp[i-2]+count[i]*i);
        }
        return dp[10000];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,2};
    auto ans=sol.deleteAndEarn(nums);
    DBG(ans);

    system("pause");
    return 0;
}
