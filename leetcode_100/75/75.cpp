#include "utils.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0,j=0,k=nums.size()-1;i<=k;){
            if(nums[i]==0)swap(nums[i++],nums[j++]);
            else if(nums[i]==2)swap(nums[i],nums[k--]);
            else i++;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,0};
    sol.sortColors(nums);
    DBGV(nums);

    system("pause");
    return 0;
}
