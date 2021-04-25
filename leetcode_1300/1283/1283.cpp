#include "utils.h"

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(ALL(nums));
        while(low<high){
            int mid=low+high>>1;
            int cnt=0;
            for(int a:nums){
                cnt+=ceil(1.0*a/mid);
            }
            if(cnt<=threshold)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,5,9};
    int threshold=6;
    auto ans=sol.smallestDivisor(nums,threshold);
    DBG(ans);

    system("pause");
    return 0;
}
