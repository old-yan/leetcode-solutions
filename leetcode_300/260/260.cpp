#include "utils.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask=0;
        for(int a:nums)mask^=a;
        int zeros=__builtin_ctz(mask);
        int x=0;
        for(int a:nums){
            if(a&(1<<zeros))x^=a;
        }
        return {x,mask^y};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,1,3,2,5};
    auto ans=sol.singleNumber(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
