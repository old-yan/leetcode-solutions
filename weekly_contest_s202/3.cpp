#include "utils.h"

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        //求出前缀和数组
        auto sum=presum(nums);
        int total=sum.back();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,2,2,5,0};
    auto ans=sol.waysToSplit(nums);
    DBG(ans);

    system("pause");
    return 0;
}
