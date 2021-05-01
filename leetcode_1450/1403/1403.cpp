#include "utils.h"

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum=accumulate(ALL(nums),0);
        sort(ALLR(nums));
        vi ans;
        int cur=0;
        for(int a:nums){
            ans.pb(a);
            if((cur+=a)>sum/2)break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,3,10,9,8};
    auto ans=sol.minSubsequence(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
