#include "utils.h"

class Solution {
    const int MOD=1000000007;
public:
    //本题为快速幂裸题，看到题目数据范围，请直接打消暴力念头
    int countGoodNumbers(long long n) {
        long long ans=1;
        //偶数位上有五种选择
        ans=ans*fastPower(5,(n+1)/2)%MOD;
        //奇数位上有四种选择
        ans=ans*fastPower(4,n/2)%MOD;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    long long n=100;
    auto ans=sol.countGoodNumbers(n);
    DBG(ans);

    system("pause");
    return 0;
}
