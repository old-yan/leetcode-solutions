#include "utils.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        #define a(i) (i<0||i==nums.size()?INT_MIN:nums[i])
        while(low<high){
            int mid=(low+high)/2;
            if(a(mid)>a(mid-1)&&a(mid)>a(mid+1))return mid;
            if(a(mid)<a(mid+1))low=mid+1;
            else high=mid;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,1,3,5,6,4};
    auto ans=sol.findPeakElement(nums);
    DBG(ans);

    system("pause");
    return 0;
}
