#include "utils.h"

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(ALL(nums),greater<int>());
        auto next=next_different(nums);
        int ans=0;
        for(int i=0;i<nums.size();i=next[i]){
            if(i+2<nums.size()&&nums[i+1]+nums[i+2]>nums[i]){
                chmax(ans,nums[i]+nums[i+1]+nums[i+2]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,6,2,3};
    auto ans=sol.largestPerimeter(nums);
    DBG(ans);

    system("pause");
    return 0;
}
