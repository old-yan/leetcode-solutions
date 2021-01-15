#include "utils.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vi ans;
        int n=nums.size();
        for(int a:nums){
            a=(a-1)%n;
            nums[a]+=n;
            if(nums[a]>n*2)ans.pb(a+1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,3,2,7,8,2,3,1};
    auto ans=sol.findDuplicates(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
