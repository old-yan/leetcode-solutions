#include "utils.h"

class Solution {
public:
    //按照题意进行模拟
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(ALL(nums));
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{1,2,5,2,3};
    int target=2;
    auto ans=sol.targetIndices(nums,target);
    DBGV(ans);

    system("pause");
    return 0;
}