#include "utils.h"

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        auto rnk=getrank(nums);
        vector<string>ans;
        int n=nums.size();
        for(int a:rnk){
            if(a==n-1)ans.pb("Gold Medal");
            else if(a==n-2)ans.pb("Silver Medal");
            else if(a==n-3)ans.pb("Bronze Medal");
            else ans.pb(i2s(n-a));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,4,3,2,1};
    auto ans=sol.findRelativeRanks(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
