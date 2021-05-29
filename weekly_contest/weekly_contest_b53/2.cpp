#include "utils.h"

class Solution {
public:
    //经典贪心问题，让最大的和最小的搭配，就可以让那个最小的拖最大的后腿
    int minPairSum(vector<int>& nums) {
        sort(ALL(nums));
        int ans=0;
        for(int i=0,j=nums.size()-1;i<j;i++,j--)
            chmax(ans,nums[i]+nums[j]);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,5,2,3};
    auto ans=sol.minPairSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
