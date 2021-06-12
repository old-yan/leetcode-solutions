#include "utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0,minbefore=0;
        int ans=INT_MIN;
        for(int a:nums){
            cursum+=a;
            chmax(ans,cursum-minbefore);
            chmin(minbefore,cursum);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-2,1,-3,4,-1,2,1,-5,4};
    auto ans=sol.maxSubArray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
