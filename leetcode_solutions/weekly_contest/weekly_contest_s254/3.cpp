#include "utils.h"

class Solution {
public:
    //  这是一道数学题
    //  结论为：
    //      总共有 2^p-1 个数，令其中 一半（向下取整）为1，一半（向下取整）为 2^p-2，还有一个为 2^p-1
    //      此时乘积最小
    //  例如：
    //      p=5，共31个数，其中15个1(0b00001)，15个30(0b11110)，还有一个31(0b11111)
    int minNonZeroProduct(int p) {
        ll all=(1ll<<p)-1;
        return fastPower(1,all/2)*fastPower((all-1)%MOD,all/2)%MOD*(all%MOD)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int p=3;
    auto ans=sol.minNonZeroProduct(p);
    DBG(ans);

    system("pause");
    return 0;
}
