#include "utils.h"

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size(),sum=accumulate(ALL(nums),0);
        vi ans(n);
        for(int i=0,left=0,right=sum;i<n;i++){
            right-=nums[i];
            ans[i]=right-(n-i-1)*nums[i]+i*nums[i]-left;
            left+=nums[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,5};
    auto ans=sol.getSumAbsoluteDifferences(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
