#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int kthFactor(int n, int k) {
        static EulerPrime<1001>ep;
        ep.getFactors(n);
        if(ep.flen<k)return -1;
        nth_element(ep.factors,ep.factors+k-1,ep.factors+ep.flen);
        return ep.factors[k-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=12;
    int k=3;
    auto ans=sol.kthFactor(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
