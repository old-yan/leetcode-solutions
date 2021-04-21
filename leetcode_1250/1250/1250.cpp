#include "utils.h"

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        for(int a:nums)if(a==1)return true;
        int g=nums[0];
        for(int i=1;i<nums.size();i++){
            g=mygcd(g,nums[i]);
            if(g==1)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{12,5,7,23};
    auto ans=sol.isGoodArray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
