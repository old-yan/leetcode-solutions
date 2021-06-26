#include "utils.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0,j=-1,prod=1;i<nums.size();i++){
            while(j+1<nums.size()&&prod*nums[j+1]<k)prod*=nums[++j];
            ans+=j-i+1;
            if(i<=j)prod/=nums[i];
            else j++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{10,5,2,6};
    int k=100;
    auto ans=sol.numSubarrayProductLessThanK(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
