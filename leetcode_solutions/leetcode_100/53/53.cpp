#include "utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        partial_sum(ALL(nums),nums.begin());
        int minbefore=0;
        REP(i,nums.size()){
            chmax(ans,nums[i]-minbefore);
            chmin(minbefore,nums[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-2,1,-3,4,-1,2,1,-5,4};
    auto ans=sol.maxSubArray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
