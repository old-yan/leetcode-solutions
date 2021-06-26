#include "utils.h"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1,high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            int count=0;
            for(int a:nums)if(a<=mid)count++;
            if(count<=mid)low=mid+1;
            else high=mid;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,1,3,4,3};
    auto ans=sol.findDuplicate(nums);
    DBG(ans);

    system("pause");
    return 0;
}
