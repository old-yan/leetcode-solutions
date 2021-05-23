#include "utils.h"

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        REP(state,1<<n){
            int cnt=0;
            REP(j,n)if(state>>j&1){
                cnt^=nums[j];
            }
            ans+=cnt;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3};
    auto ans=sol.subsetXORSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
