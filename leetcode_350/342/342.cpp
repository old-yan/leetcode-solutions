#include "utils.h"

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        while(n%4==0)n/=4;
        return n==1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=64;
    auto ans=sol.isPowerOfFour(n);
    DBG(ans);

    system("pause");
    return 0;
}
