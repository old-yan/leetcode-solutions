#include "utils.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans=0;
        for(int i=0,j;i<nums.size();i=j){
            for(j=i+1;j<nums.size()&&nums[j]>nums[i];j++);
            chmax(ans,j-i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,5,4,7};
    auto ans=sol.findLengthOfLCIS(nums);
    DBG(ans);

    system("pause");
    return 0;
}
