#include "utils.h"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int del=0;
        REP(i,nums.size()-1){
            if(nums[i+1]<nums[i]){
                if(++del>1)return false;
                if(i&&nums[i+1]<nums[i-1]){
                    if(i+2<nums.size()&&nums[i]>nums[i+2])return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,2,3};
    auto ans=sol.checkPossibility(nums);
    DBG(ans);

    system("pause");
    return 0;
}
