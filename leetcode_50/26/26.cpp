#include "utils.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //return unique(nums.begin(),nums.end())-nums.begin();
        int i,j,k;
        for(i=k=0;i<nums.size();i=j){
            for(j=i+1;j<nums.size()&&nums[j]==nums[i];j++);
            swap(nums[k++],nums[i]);
        }
        return k;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,0,1,1,1,2,2,3,3,4};
    auto ans=sol.removeDuplicates(nums);
    DBG(ans);
    DBGV(nums);

    system("pause");
    return 0;
}
