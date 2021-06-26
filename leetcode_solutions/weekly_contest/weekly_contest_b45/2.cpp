#include "utils.h"

class Solution {
public:
    //绝对值最大，要么是正的很大，要么是负的很小
    int maxAbsoluteSum(vector<int>& nums) {
        partial_sum(ALL(nums),nums.begin());
        int Max=max(0,*max_element(ALL(nums)));
        int Min=min(0,*min_element(ALL(nums)));
        return Max-Min;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,-5,1,-4,3,-2};
    auto ans=sol.maxAbsoluteSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
