#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int countPrimes(int n) {
        static EulerPrime<1500000>ep;
        int low=0,high=ep.lv;
        while(low<high){
            int mid=(low+high)/2;
            if(ep.v[mid]>=n)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.countPrimes(n);
    DBG(ans);

    system("pause");
    return 0;
}
