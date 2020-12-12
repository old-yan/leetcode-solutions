#include "utils.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2)return;
        int i,j;
        for(i=nums.size()-2;i>=0;i--)if(nums[i]<nums[i+1])break;
        if(i>=0){
            for(j=nums.size()-1;;j--)if(nums[j]>nums[i])break;
            swap(nums[i],nums[j]);
        }
        sort(nums.begin()+i+1,nums.end());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,5,2,4,3,1};
    sol.nextPermutation(nums);
    DBGV(nums);

    system("pause");
    return 0;
}
