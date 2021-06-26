#include "utils.h"

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n)return false;
        while(n%3==0)n/=3;
        return n==1;
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=729;
    auto ans=sol.isPowerOfThree(n);
    DBG(ans);

    system("pause");
    return 0;
}
