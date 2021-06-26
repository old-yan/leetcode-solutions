#include "utils.h"

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        ll total=accumulate(ALL(nums),0);
        ll low=(ll)*max_element(ALL(nums)),high=total;
        while(low<high){
            ll mid=(low+high)/2;
            int num=0,cur=0;
            for(int a:nums){
                if(cur+a<mid)cur+=a;
                else{
                    num++;
                    cur=a;
                }
            }
            num++;
            if(num<=m)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{7,2,5,10,8};
    int m=2;
    auto ans=sol.splitArray(nums,m);
    DBG(ans);

    system("pause");
    return 0;
}
