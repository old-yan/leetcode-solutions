#include "utils.h"

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vi ans(1<<n);
        REP(i,1<<n)ans[i]=i^(i>>1)^start;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    int start=2;
    auto ans=sol.circularPermutation(n,start);
    DBGV(ans);

    system("pause");
    return 0;
}
