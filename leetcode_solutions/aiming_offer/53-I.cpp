#include "utils.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return upper_bound(ALL(nums),target)-lower_bound(ALL(nums),target);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,7,7,8,8,10};
    int target=8;
    auto ans=sol.search(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}
