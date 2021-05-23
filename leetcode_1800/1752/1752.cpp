#include "utils.h"

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<bool>v(nums.size());
        REP(i,nums.size()){
            v[i]=nums[(i+1)%nums.size()]>=nums[i];
        }
        return count(ALL(v),false)<=1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,5,4,1,2};
    auto ans=sol.check(nums);
    DBG(ans);

    system("pause");
    return 0;
}
