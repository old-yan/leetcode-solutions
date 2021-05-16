#include "utils.h"

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(!n)return 0;
        vi nums(n+1);
        nums[0]=0;
        nums[1]=1;
        FOR(i,2,n+1){
            if(i%2==0)nums[i]=nums[i/2];
            else nums[i]=nums[i/2]+nums[i/2+1];
        }
        return *max_element(ALL(nums));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    auto ans=sol.getMaximumGenerated(n);
    DBG(ans);

    system("pause");
    return 0;
}
