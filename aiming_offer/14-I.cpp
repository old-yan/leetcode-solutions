#include "utils.h"

class Solution {
public:
    int cuttingRope(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        else if(n%3==0)return fastPower(3,n/3,LLONG_MAX);
        else if(n%3==1)return fastPower(3,(n-4)/3,LLONG_MAX)*4;
        else return fastPower(3,(n-2)/3,LLONG_MAX)*2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=8;
    auto ans=sol.cuttingRope(n);
    DBG(ans);

    system("pause");
    return 0;
}
