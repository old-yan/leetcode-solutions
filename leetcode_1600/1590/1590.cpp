#include "utils.h"

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        ll sum=accumulate(ALL(nums),0ll);
        if(sum%p==0)return 0;
        unordered_map<int,int>M;
        M[0]=-1;
        ll presum=0,ans=nums.size();
        REP(i,nums.size()){
            presum=(presum+nums[i])%p;
            int target=(presum+p-sum%p)%p;
            if(M.count(target)){
                chmin(ans,i-M[target]);
            }
            M[presum]=i;
        }
        return ans==nums.size()?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,1,4,2};
    int p=6;
    auto ans=sol.minSubarray(nums,p);
    DBG(ans);

    system("pause");
    return 0;
}
