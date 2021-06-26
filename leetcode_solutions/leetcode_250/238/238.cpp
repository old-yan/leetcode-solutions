#include "utils.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vi ans(nums.size(),1);
        ll j=1;
        REP(i,nums.size()){
            ans[i]*=j;
            j*=nums[i];
        }
        j=1;
        REPR(i,nums.size()-1){
            ans[i]*=j;
            j*=nums[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    auto ans=sol.productExceptSelf(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
