#include "utils.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    uint32_t n=0b00000000000000000000000000001011;
    auto ans=sol.hammingWeight(n);
    DBG(ans);

    system("pause");
    return 0;
}
