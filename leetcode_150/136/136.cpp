#include "utils.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i=0;
        for(int a:nums)i^=a;
        return i;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,1,2,1,2};
    auto ans=sol.singleNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
