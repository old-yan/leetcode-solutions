#include "utils.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(ALL(nums));
        return nums;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,1,1,2,0,0};
    auto ans=sol.sortArray(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
