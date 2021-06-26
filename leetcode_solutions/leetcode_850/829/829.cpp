#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        static EulerPrime<40000>ep;
        ep.getFactors(N);
        int ans=0;
        REP(_,ep.flen){
            int a=ep.factors[_];
            int n=N/a;
            if(n%2&&a-n/2>0)ans++;
            if(a%2&&a/2>=n)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=1000;
    auto ans=sol.consecutiveNumbersSum(N);
    DBG(ans);

    system("pause");
    return 0;
}
