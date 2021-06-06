#include "utils.h"

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(ALL(nums));
        int ans=INT_MIN;
        for(int i=0,j=nums.size()-1;i<j;i++,j--){
            chmax(ans,nums[i]+nums[j]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,5,2,3};
    auto ans=sol.minPairSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
