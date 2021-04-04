#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int minSteps(int n) {
        static EulerPrime<31>ep;
        ep.getPrimeFactors<1>(n);
        int ans=0;
        REP(_,ep.plen){
            ans+=ep.pf[_]*ep.pcnt[_];
        }
        return ans;
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
