#include "utils.h"

class Solution {
public:
    int numWays(int n) {
        static int dp[101]={1,1};
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
    auto ans=sol.numWays(n);
    DBG(ans);

    system("pause");
    return 0;
}
