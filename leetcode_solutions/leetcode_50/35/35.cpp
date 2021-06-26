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
    int searchInsert(vector<int>& nums, int target) {
        //return lower_bound(ALL(nums),target)-nums.begin();
        int lowerbound=bs(nums,target);
        return lowerbound;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,5,6};
    auto ans=sol.searchInsert(nums,5);
    DBG(ans);    

    system("pause");
    return 0;
}
