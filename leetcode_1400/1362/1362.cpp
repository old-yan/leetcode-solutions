#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    vector<int> closestDivisors(int num) {
        static EulerPrime<40000>ep;
        ep.getFactors(num+1);
        sort(ep.factors,ep.factors+ep.flen);
        int a=*lower_bound(ep.factors,ep.factors+ep.flen,sqrt(num+1));
        int b=(num+1)/a;
        ep.getFactors(num+2);
        sort(ep.factors,ep.factors+ep.flen);
        int c=*lower_bound(ep.factors,ep.factors+ep.flen,sqrt(num+2));
        int d=(num+2)/c;
        printf("%d %d %d%d\n",a,b,c,d);
        if(abs(a-b)<abs(c-d))return {a,b};
        else return {c,d};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=4;
    auto ans=sol.closestDivisors(num);
    DBGV(ans);

    system("pause");
    return 0;
}
