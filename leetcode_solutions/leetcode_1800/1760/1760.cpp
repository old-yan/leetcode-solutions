#include "utils.h"

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1,high=*max_element(ALL(nums));
        while(low<high){
            int mid=(low+high)/2;
            int cnt=0;
            for(int a:nums)cnt+=(a+mid-1)/mid-1;
            if(cnt>maxOperations)low=mid+1;
            else high=mid;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,4,8,2};
    int maxOperations=4;
    auto ans=sol.minimumSize(nums,maxOperations);
    DBG(ans);

    system("pause");
    return 0;
}
