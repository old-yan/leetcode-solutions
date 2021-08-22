#include "utils.h"

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return mygcd(*min_element(ALL(nums)),*max_element(ALL(nums)));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,5,6,9,10};
    auto ans=sol.findGCD(nums);
    DBG(ans);

    system("pause");
    return 0;
}
