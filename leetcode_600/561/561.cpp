#include "utils.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(ALL(nums));
        int ans=0;
        for(int i=0;i<nums.size();i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,4,3,2};
    auto ans=sol.arrayPairSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
