#include "utils.h"

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        else if(n%3==0)return fastPower(3,n/3);
        else if(n%3==1)return fastPower(3,(n-4)/3)*4%MOD;
        else return fastPower(3,(n-2)/3)*2%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.cuttingRope(n);
    DBG(ans);

    system("pause");
    return 0;
}
