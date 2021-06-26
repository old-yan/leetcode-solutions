#include "utils.h"

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return __builtin_popcount(n^(n>>1))==32-__builtin_clz(n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=11;
    auto ans=sol.hasAlternatingBits(n);
    DBG(ans);

    system("pause");
    return 0;
}
