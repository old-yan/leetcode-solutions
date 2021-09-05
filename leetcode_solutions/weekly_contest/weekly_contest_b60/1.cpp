#include "utils.h"

class Solution {
public:
    //从左往右，找到的第一个下标就是答案
    int findMiddleIndex(vector<int>& nums) {
        int sum=accumulate(ALL(nums),0);
        int left=0;
        for(int i=0;i<nums.size();left+=nums[i],i++){
            int cur=nums[i];
            if(left==sum-cur-left)return i;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,-1,8,4};
    auto ans=sol.findMiddleIndex(nums);
    DBG(ans);

    system("pause");
    return 0;
}
