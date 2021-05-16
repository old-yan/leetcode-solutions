#include "utils.h"

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int sum[n+1];
        sum[0]=0;
        partial_sum(ALL(nums),sum+1);
        int Max=*max_element(sum,sum+n+1);
        int Min=*min_element(sum,sum+n+1);
        return abs(Max-Min);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,-3,2,3,-4};
    auto ans=sol.maxAbsoluteSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
