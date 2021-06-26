#include "utils.h"

class Solution {
public:
    int sumBase(int n, int k) {
        string s=i2s(n,k);
        return accumulate(ALL(s),0,[](int x,char y){return x+(y-'0');});
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
