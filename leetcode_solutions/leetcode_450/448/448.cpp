#include "utils.h"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int a:nums){
            a=(a-1)%n;
            nums[a]+=n;
        }
        vi ans;
        REP(i,n){
            if(nums[i]<=n)ans.pb(i+1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,3,2,7,8,2,3,1};
    auto ans=sol.findDisappearedNumbers(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
