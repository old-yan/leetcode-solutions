#include "utils.h"

class Solution {
public:
    //模拟即可
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(nums.end(),nums.begin(),nums.end());
        return nums;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.getConcatenation(nums);
    DBGV(ans);
    
    system("pause");
    return 0;
}
