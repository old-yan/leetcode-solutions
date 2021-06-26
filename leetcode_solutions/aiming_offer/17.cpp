#include "utils.h"

class Solution {
public:
    vector<int> printNumbers(int n) {
        vi ans;
        int m=pow(10,n);
        ans.reserve(m-1);
        FOR(i,1,m){
            ans.pb(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=1;
    auto ans=sol.printNumbers(n);
    DBGV(ans);

    system("pause");
    return 0;
}
