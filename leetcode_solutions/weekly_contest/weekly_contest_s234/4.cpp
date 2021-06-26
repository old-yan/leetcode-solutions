#include "utils.h"

class Solution {
public:
    // 如果有一个数字可以被分解为p1^k1 * p2^k2 * p3^k3 * ... * pn^kn
    // 其中 p1,p2,p3,...,pn均为不同的质数
    // 那么它的好因子数量为 k1*k2*k3*...*kn
    // 根据题意，k1+k2+k3+...+kn=primeFactors
    // 在和一定的情况下，令积最大，就要尽可能地3个3个地分割
    // 只有当最后剩下4的情况下，分成2*2比分成3*1更好

    // 为什么不分割4或者4以上的大块？设m>=4,则(m-2)*2>=m，所以m肯定可以继续分
    // 为什么尽量分割3而不是分割2？如果我们有3个2，那么2*2*2<3*3，所以每当有3个2，可以换成2个3，会是更优
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors==1)return 1;
        int n=primeFactors/3,m=primeFactors%3;
        if(m==1){
            return fastPower(3,n-1)*4%MOD;
        }
        else if(m==2){
            return fastPower(3,n)*2%MOD;
        }
        else{
            return fastPower(3,n);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int primeFactors=1000;
    auto ans=sol.maxNiceDivisors(primeFactors);
    DBG(ans);

    system("pause");
    return 0;
}
