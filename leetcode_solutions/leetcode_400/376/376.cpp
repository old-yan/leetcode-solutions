#include "utils.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())return 0;
        int up=1,down=1;
        FOR(i,1,nums.size()){
            if(nums[i]>nums[i-1]){
                up=down+1;
            }
            else if(nums[i]<nums[i-1]){
                down=up+1;
            }
        }
        return max(up,down);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{33,53,12,3,9};
    auto ans=sol.wiggleMaxLength(nums);
    DBG(ans);

    system("pause");
    return 0;
}
