#include "utils.h"

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors<=3)return primeFactors;
        if(primeFactors%3==2)
            return 2*fastPower(3,(primeFactors-2)/3)%MOD;
        else if(primeFactors%3==1)
            return 4*fastPower(3,(primeFactors-4)/3)%MOD;
        else
            return fastPower(3,primeFactors/3)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int primeFactors=5;
    auto ans=sol.maxNiceDivisors(primeFactors);
    DBG(ans);

    system("pause");
    return 0;
}
