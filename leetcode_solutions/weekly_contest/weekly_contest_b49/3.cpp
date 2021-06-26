#include "utils.h"

class Solution {
public:
    //如果 nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    //那么 nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    //定义新数组 dif[i]=nums[i] - rev(nums[i])
    //那么求的就是dif数组中的相同值对
    int countNicePairs(vector<int>& nums) {
        ll dif[nums.size()];
        for(int i=0;i<nums.size();i++){
            ll reversed=0;
            for(int b=nums[i];b;b/=10)reversed=reversed*10+b%10;
            dif[i]=nums[i]-reversed;
        }
        unordered_map<ll,int>M;
        ll ans=0;        
        for(int a:dif){
            ans=(ans+M[a]++)%MOD;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{13,10,35,24,76};
    auto ans=sol.countNicePairs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
