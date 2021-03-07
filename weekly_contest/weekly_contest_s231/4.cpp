#include "utils.h"

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,5,2,1,7,3,4,7};
    int k=3;
    auto ans=sol.minChanges(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
