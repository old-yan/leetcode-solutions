#include "utils.h"

class Solution {
public:
    //对数组排序后，取所有的k长子数组，就可以找到答案
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=10000000;
        for(int i=0;;i++){
            //当右界超出数组范围时，break
            if(i+k>nums.size())break;
            ans=min(ans,nums[i+k-1]-nums[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{9,4,1,7};
    int k=2;
    auto ans=sol.minimumDifference(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
