#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int minSteps(int n) {
        static EulerPrime<31>ep;
        vi factors=ep.getFactors<1>(n);
        return accumulate(ALL(factors),0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.minSteps(n);
    DBG(ans);

    system("pause");
    return 0;
}
