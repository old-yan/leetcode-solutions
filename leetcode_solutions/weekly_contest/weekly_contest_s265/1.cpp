#include "utils.h"

class Solution {
public:
    //遍历找答案
    int smallestEqual(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i%10==nums[i])return i;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{4,3,2,1};
    auto ans=sol.smallestEqual(nums);
    DBG(ans);

    system("pause");
    return 0;
}