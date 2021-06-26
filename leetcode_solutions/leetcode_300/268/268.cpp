#include "utils.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        bool havezero=false;
        for(int a:nums)if(!a)havezero=true;
        if(!havezero)return 0;
        for(int&a:nums)if(a<=0)a=n+1;
        for(int a:nums){
            if(abs(a)<n){
                nums[abs(a)]=-abs(nums[abs(a)]);
            }
        }
        FOR(i,1,n)if(nums[i]>0)return i;
        return n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,2};
    auto ans=sol.missingNumber(nums);
    DBG(ans);

    system("pause");
    return 0;
}
