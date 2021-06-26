#include "utils.h"

class Solution {
public:
    //每次找一个单调区间，并尝试更新ans
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0,j;i<n;i=j){
            int sum=nums[i];
            for(j=i+1;j<n&&nums[j]>nums[j-1];j++)sum+=nums[j];
            chmax(ans,sum);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{10,20,30,5,10,50};
    auto ans=sol.maxAscendingSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
