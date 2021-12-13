#include "utils.h"

class Solution {
public:
    //观察数据范围可知，O(n^2)的复杂度是可行的
    //那么我们枚举每个子区间即可，但是子区间的最值不要重新计算，而要在上一个子区间的最值基础上修改得来
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        for(int left=0;left<nums.size();left++){
            int Min=INT_MAX,Max=INT_MIN;
            for(int right=left;right<nums.size();right++){
                Min=min(Min,nums[right]);
                Max=max(Max,nums[right]);
                ans+=Max-Min;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{4,-2,-3,4,1};
    auto ans=sol.subArrayRanges(nums);
    DBG(ans);

    system("pause");
    return 0;
}