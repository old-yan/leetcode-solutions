#include "utils.h"

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(ALLR(nums));
        ll ans=0;
        for(int i=0,j;i<nums.size();i=j){
            for(j=i+1;j<nums.size()&&nums[j]==nums[i];j++);
            ans+=i;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,1,3};
    auto ans=sol.reductionOperations(nums);
    DBG(ans);

    system("pause");
    return 0;
}
