#include "utils.h"

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(ALL(nums));
        ll ans=0;
        for(int left=nums.size()-1,right=0;right<nums.size();right++){
            while(left>=0&&nums[left]+nums[right]>target)left--;
            if(left<0)break;
            if(left>=right){
                ans+=fastPower(2,right);
            }
            else{
                ans+=(fastPower(2,left+1)-1)*fastPower(2,right-left-1);
                ans%=MOD;
            }
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,5,6,7};
    int target=9;
    auto ans=sol.numSubseq(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}
