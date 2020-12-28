#include "utils.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0,j=0,sum=0;i<nums.size();){
            if(sum<s){
                if(j<nums.size())sum+=nums[j++];
                else break;
            }
            else{
                chmin(ans,j-i);
                sum-=nums[i++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int s=7;
    vi nums{2,3,1,2,4,3};
    auto ans=sol.minSubArrayLen(s,nums);
    DBG(ans);

    system("pause");
    return 0;
}
