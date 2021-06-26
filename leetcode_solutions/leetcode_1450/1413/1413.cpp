#include "utils.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        partial_sum(ALL(nums),nums.begin());
        return 1-min(*min_element(ALL(nums)),0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-3,2,-3,4,2};
    auto ans=sol.minStartValue(nums);
    DBG(ans);

    system("pause");
    return 0;
}
