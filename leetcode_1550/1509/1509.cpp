#include "utils.h"

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)return 0;
        nth_element(nums.begin(),nums.begin()+3,nums.end());
        nth_element(nums.begin()+4,nums.end()-4,nums.end());
        sort(nums.begin(),nums.begin()+3);
        sort(nums.end()-4,nums.end());
        int ans=INT_MAX;
        chmin(ans,nums.back()-nums[3]);
        chmin(ans,nums[nums.size()-2]-nums[2]);
        chmin(ans,nums[nums.size()-3]-nums[1]);
        chmin(ans,nums[nums.size()-4]-nums[0]);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,3,2,4};
    auto ans=sol.minDifference(nums);
    DBG(ans);

    system("pause");
    return 0;
}
