#include "utils.h"

class Solution {
public:
    //直接调用我写好的库函数转成字符串
    int sumBase(int n, int k) {
        string s=i2s(n,k);
        return accumulate(ALL(s),0,[](int x,char c){return x+c-'0';});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=34;
    int k=6;
    auto ans=sol.sumBase(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
