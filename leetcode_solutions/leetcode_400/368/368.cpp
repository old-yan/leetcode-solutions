#include "utils.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(ALL(nums));
        int dp[nums.size()];
        int Max=INT_MIN;
        REP(i,nums.size()){
            int k=1;
            REP(j,i){
                if(nums[i]%nums[j]==0)chmax(k,dp[j]+1);
            }
            dp[i]=k;
            chmax(Max,dp[i]);
        }
        vi ans;
        REPR(i,nums.size()-1){
            if(dp[i]==Max&&(ans.empty()||ans.back()%nums[i]==0)){
                ans.pb(nums[i]);
                Max--;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,4,7,8,10};
    auto ans=sol.largestDivisibleSubset(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
