#include "utils.h"

class Solution {
    vi nums;
    int bs(){
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]<nums.back())high=mid;
            else low=mid+1;
        }
        return low;
    }
public:
    int findMin(vector<int>&_nums) {
        nums=_nums;
        return nums[bs()];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,5,1,2};
    auto ans=sol.findMin(nums);
    DBG(ans);

    system("pause");
    return 0;
}
