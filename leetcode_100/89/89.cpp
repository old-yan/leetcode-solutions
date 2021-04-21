#include "utils.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vi ans(1<<n);
        REP(i,1<<n)ans[i]=i^(i>>1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.grayCode(n);
    DBGV(ans);

    system("pause");
    return 0;
}

//  0   0   0
//  0   0   1
//  0   1   1
//  0   1   0
//  1   1   0
//  1   1   1
//  1   0   1
//  1   0   0
