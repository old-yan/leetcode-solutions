#include "utils.h"

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vi ans;
        REP(i,n){
            ans.pb(nums[i]);
            ans.pb(nums[i+n]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,5,1,3,4,7};
    int n=3;
    auto ans=sol.shuffle(nums,n);
    DBGV(ans);

    system("pause");
    return 0;
}
