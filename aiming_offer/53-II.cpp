#include "utils.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        return n*(n+1)/2-accumulate(ALL(nums),0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,3};
    auto ans=sol.missingNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
