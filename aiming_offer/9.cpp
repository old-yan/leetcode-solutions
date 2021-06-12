#include "utils.h"

class Solution {
public:
    int fib(int n) {
        static int dp[101]={0,1};
        FOR(i,2,n+1){
            dp[i]=(dp[i-2]+dp[i-1])%MOD;
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.fib(n);
    DBG(ans);

    system("pause");
    return 0;
}
