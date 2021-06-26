#include "utils.h"

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab=mylcm(a,b);
        ll bc=mylcm(b,c);
        ll ac=mylcm(a,c);
        ll abc=mylcm(ab,c);
        ll low=1,high=0x3f3f3f3f3f;
        while(low<high){
            ll mid=(low+high)/2;
            ll num=mid/a+mid/b+mid/c-mid/ab-mid/ac-mid/bc+mid/abc;
            if(num<n)low=mid+1;
            else high=mid;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=1000000000;
    int a=2;
    int b=217983653;
    int c=336916467;
    auto ans=sol.nthUglyNumber(n,a,b,c);
    DBG(ans);

    system("pause");
    return 0;
}
