#include "utils.h"

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            if(nums[i]==i)return i;
            else if(nums[i]>i)i=nums[i];
            else i++;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,2,3,4,5};
    auto ans=sol.findMagicIndex(nums);
    DBG(ans);

    system("pause");
    return 0;
}
