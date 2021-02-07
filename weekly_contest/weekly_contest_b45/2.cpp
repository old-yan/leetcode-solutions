#include "utils.h"

class Solution {
public:
    //绝对值最大，要么是正的很大，要么是负的很小
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0;
        //sum记录前缀和
        auto sum=presum(nums);
        //答案就是前缀和数组中，最高峰与最低谷的差
        return *max_element(ALL(sum))-*min_element(ALL(sum));
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
