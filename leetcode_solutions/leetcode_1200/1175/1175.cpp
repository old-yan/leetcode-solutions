#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int numPrimeArrangements(int n) {
        static EulerPrime<1000>ep;
        int low=0,high=ep.lv;
        while(low<high){
            int mid=(low+high)/2;
            if(ep.v[mid]<=n)low=mid+1;
            else high=mid;
        }
        ll ans=factorial(low)*factorial(n-low)%MOD;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    auto ans=sol.numPrimeArrangements(n);
    DBG(ans);

    system("pause");
    return 0;
}
