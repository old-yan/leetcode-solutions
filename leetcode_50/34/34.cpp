#include "utils.h"

class Solution {
    int bs(vi& v,int target){
        int low = 0,high = v.size();
        while (low<high){
            int mid = (high + low) / 2;
            if (v[mid]>=target)high = mid;
            else low = mid+1;
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerbound=bs(nums,target);
        if(lowerbound==nums.size()||nums[lowerbound]!=target)return {-1,-1};
        int upperbound=bs(nums,target+1);
        return {lowerbound,upperbound-1};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,7,7,8,8,10};
    auto ans=sol.searchRange(nums,8);
    DBGV(ans);

    system("pause");
    return 0;
}
