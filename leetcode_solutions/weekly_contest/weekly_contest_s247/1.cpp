#include "utils.h"

class Solution {
public:
    //贪心思想，让a,b最大，c,d最小
    int maxProductDifference(vector<int>& nums) {
        sort(ALL(nums));
        int a=nums[nums.size()-1];
        int b=nums[nums.size()-2];
        int c=nums[01];
        int d=nums[0];
        return a*b-c*d;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,6,2,7,4};
    auto ans=sol.maxProductDifference(nums);
    DBG(ans);

    system("pause");
    return 0;
}
