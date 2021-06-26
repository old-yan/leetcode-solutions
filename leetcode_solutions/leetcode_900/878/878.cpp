#include "utils.h"

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll c=lcm(a,b);
        int d=c/a+c/b-1;
        ll low=0,high=c-1;
        while(low<high){
            ll mid=(low+high)/2;
            if(mid/a+mid/b>=n%d)high=mid;
            else low=mid+1;
        }
        return (c*(n/d)+low)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    int a=2;
    int b=3;
    auto ans=sol.nthMagicalNumber(n,a,b);
    DBG(ans);

    system("pause");
    return 0;
}
