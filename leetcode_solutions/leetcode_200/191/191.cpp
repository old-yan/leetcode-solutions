#include "utils.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        //return __builtin_popcount(n);
        bitset<32>b(n);
        return b.count();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    uint32_t n=s2i("11111111111111111111111111111101",2);
    auto ans=sol.hammingWeight(n);
    DBG(ans);

    system("pause");
    return 0;
}
