#include "utils.h"

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(ALL(nums),nums.begin());
        return nums;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    auto ans=sol.runningSum(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
