#include "utils.h"

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(ALL(nums));
        int des=nums[nums.size()/2];
        int ans=0;
        for(int a:nums){
            ans+=abs(a-des);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.minMoves2(nums);
    DBG(ans);

    system("pause");
    return 0;
}
