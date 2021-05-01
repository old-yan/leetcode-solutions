#include "utils.h"

class Solution {
public:
    int countOrders(int n) {
        return factorial(n*2)*inv(fastPower(2,n))%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.countOrders(n);
    DBG(ans);

    system("pause");
    return 0;
}