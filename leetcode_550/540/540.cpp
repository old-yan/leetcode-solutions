#include "utils.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int cnt=0;
        for(int a:nums)cnt^=a;
        return cnt;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,2,2,3,4,4,8,8};
    auto ans=sol.singleNonDuplicate(nums);
    DBG(ans);

    system("pause");
    return 0;
}
