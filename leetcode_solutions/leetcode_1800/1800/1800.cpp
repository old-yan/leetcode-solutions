#include "utils.h"

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        for(int i=0,j;i<nums.size();i=j){
            for(j=i+1;j<nums.size()&&nums[j]>nums[j-1];j++);
            chmax(ans,accumulate(nums.begin()+i,nums.begin()+j,0));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{10,20,30,5,10,50};
    auto ans=sol.maxAscendingSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
