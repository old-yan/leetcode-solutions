#include "utils.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        bitset<32>b1(m);
        bitset<32>b2(n);
        int lowest_same;
        for(lowest_same=31;b1[lowest_same]==b2[lowest_same];lowest_same--)if(lowest_same<0)break;
        while(lowest_same>=0)b1.reset(lowest_same--);
        return b1.to_ulong();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=100;
    int n=200;
    auto ans=sol.rangeBitwiseAnd(m,n);
    DBG(ans);

    system("pause");
    return 0;
}
