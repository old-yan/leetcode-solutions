#include "utils.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&__builtin_popcount(n)==1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=64;
    auto ans=sol.isPowerOfTwo(n);
    DBG(ans);

    system("pause");
    return 0;
}
