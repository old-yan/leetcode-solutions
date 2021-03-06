#include "utils.h"

class Solution {
    vi nums;
    int target;
    int bs(){
        int low = 0,high = nums.size()-1;
        while (low<high){
            if(nums[low]<nums[high])return low;
            int mid = (high + low) / 2;
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
    int bs2(int low,int high){
        while (low<high){
            int mid = (high + low) / 2;
            if (nums[mid]>=target)high = mid;
            else low = mid+1;
        }
        return low;
    }
public:
    bool search(vector<int>&_nums, int _target) {
        nums=_nums;
        if(nums.empty())return false;
        target=_target;
        int start=bs();
        int lowerbound;
        if(target<=nums.back())lowerbound=bs2(start,nums.size()-1);
        else lowerbound=bs2(0,start);
        return nums[lowerbound]==target;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,3,1};
    auto ans=sol.search(nums,3);
    DBG(ans);

    system("pause");
    return 0;
}
