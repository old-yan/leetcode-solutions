#include "utils.h"

class Solution {
public:
    int concatenatedBinary(int n) {
        ll cur=0;
        FOR(i,1,n+1){
            cur=(cur*(1<<(32-__builtin_clz(i)))+i)%MOD;
        }
        return cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.concatenatedBinary(n);
    DBG(ans);

    system("pause");
    return 0;
}
