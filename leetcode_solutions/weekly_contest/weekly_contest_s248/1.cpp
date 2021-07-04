#include "utils.h"

class Solution {
public:
    //直接模拟生成
    vector<int> buildArray(vector<int>& nums) {
        vi ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,2,1,5,3,4};
    auto ans=sol.buildArray(nums)
    DBGV(ans);

    system("pause");
    return 0;
}
