#include "utils.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        for(int i=0,j;i<nums.size();i=j){
            for(j=i+1;j<nums.size()&&nums[j]==nums[j-1]+1;j++);
            if(j==i+1)ans.pb(i2s(nums[i]));
            else ans.pb(i2s(nums[i])+"->"+i2s(nums[j-1]));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,2,4,5,7};
    auto ans=sol.summaryRanges(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
