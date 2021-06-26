#include "utils.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        nth_element(nums.begin(),nums.begin()+1,nums.end(),greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,5,2};
    auto ans=sol.maxProduct(nums);
    DBG(ans);

    system("pause");
    return 0;
}
