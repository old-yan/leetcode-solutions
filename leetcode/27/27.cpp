#include "utils.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,j;
        for(i=j=0;i<nums.size();i++){
            if(nums[i]!=val)nums[j++]=nums[i];
        }
        return j;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,2,2,3,0,4,2};
    int val=2;
    auto ans=sol.removeElement(nums,val);
    DBG(ans);
    DBGV(nums);

    system("pause");
    return 0;
}
