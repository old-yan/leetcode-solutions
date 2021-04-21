#include "utils.h"

class Solution {
public:
    int tribonacci(int n) {
        ll a[38];
        a[0]=0,a[1]=a[2]=1;
        FOR(i,3,38){
            a[i]=a[i-3]+a[i-2]+a[i-1];
        }
        return a[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.tribonacci(n);
    DBG(ans);

    system("pause");
    return 0;
}
