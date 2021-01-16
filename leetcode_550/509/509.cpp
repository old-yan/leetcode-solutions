#include "utils.h"

class Solution {
public:
    int fib(int n) {
        int dp[31];
        dp[0]=0;
        dp[1]=1;
        FOR(i,2,n+1){
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=20;
    auto ans=sol.fib(n);
    DBG(ans);

    system("pause");
    return 0;
}
