#include "utils.h"

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        Union u(nums.size());
        REP(i,nums.size()){
            u.unite(i,nums[i]);
        }
        return *max_element(u.size,u.size+nums.size());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,4,0,3,1,6,2};
    auto ans=sol.arrayNesting(nums);
    DBG(ans);

    system("pause");
    return 0;
}
