#include "utils.h"

class Solution {
    vi nums;
    int bs(){
        int low=0,high=nums.size()-1;
        while(low<high){
            if(nums[low]<nums[high])return low;
            int mid=(low+high)/2;
            if(nums[low]>nums[high]){
                if(nums[mid]<=nums[high])high=mid;
                else low=mid+1;
            }
            else{
                if(nums[mid]<nums[high])high=mid;
                else if(nums[mid]>nums[low])low=mid+1;
                else{
                    while(high>mid&&nums[high]==nums[mid])high--;
                    if(nums[high]>nums[mid])return high+1;
                }
            }
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

    vi nums{2,2,2,0,1};
    auto ans=sol.findMin(nums);
    DBG(ans);

    system("pause");
    return 0;
}
