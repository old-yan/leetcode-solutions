#include "utils.h"

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int a:nums){
            if(nums[a&0x3fffffff]>>31&1){
                return a&0x3fffffff;
            }
            nums[a&0x3fffffff]|=1<<31;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,1,0,2,5,3};
    auto ans=sol.findRepeatNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
