#include "utils.h"

class Solution {
public:
    int sumNums(int n) {
        int a[n];
        iota(a,a+n,1);
        return accumulate(a,a+n,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.sumNums(n);
    DBG(ans);

    system("pause");
    return 0;
}
