#include "utils.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j;
        for(i=0,j=0;i<nums.size();i++){
            if(j<2||(nums[i]!=nums[j-1]||nums[i]!=nums[j-2])){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,0,1,1,1,1,2,3,3};
    auto ans=sol.removeDuplicates(nums);
    DBG(ans);
    DBGV(nums);

    system("pause");
    return 0;
}
