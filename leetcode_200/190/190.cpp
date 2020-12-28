#include "utils.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>b1(n);
        bitset<32>b2;
        REP(i,32){
            if(b1[i])b2.set(31-i);
        }
        return b2.to_ulong();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    uint32_t n=s2i("11111111111111111111111111111101",2);
    auto ans=sol.reverseBits(n);
    DBG(ans);

    system("pause");
    return 0;
}
