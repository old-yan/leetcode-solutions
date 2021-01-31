#include "utils.h"

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(ALL(nums));
        int ans=nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        if(nums[1]<0)chmax(ans,nums[0]*nums[1]*nums.back());
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    auto ans=sol.maximumProduct(nums);
    DBG(ans);

    system("pause");
    return 0;
}
