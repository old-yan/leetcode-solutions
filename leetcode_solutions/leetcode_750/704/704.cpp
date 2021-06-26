#include "utils.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>=target)high=mid;
            else low=mid+1;
        }
        return nums[low]==target?low:-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-1,0,3,5,9,12};
    int target=9;
    auto ans=sol.search(nums,target);
    DBG(ans);

    system("pause");
    return 0;
}
