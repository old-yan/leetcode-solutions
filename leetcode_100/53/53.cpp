#include "utils.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        vi _presum=presum(nums);
        int minbefore=_presum[0];
        REP(i,_presum.size()){
            chmax(ans,_presum[i+1]-minbefore);
            chmin(minbefore,_presum[i+1]);
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
