#include "utils.h"

class Solution {
public:
    int waysToChange(int n) {
        static int dp[1000001]={0};
        if(!dp[0]){
            dp[0]=1;
            FOR(i,1,1000001)dp[i]=(dp[i]+dp[i-1])%MOD;
            FOR(i,5,1000001)dp[i]=(dp[i]+dp[i-5])%MOD;
            FOR(i,10,1000001)dp[i]=(dp[i]+dp[i-10])%MOD;
            FOR(i,25,1000001)dp[i]=(dp[i]+dp[i-25])%MOD;
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    auto ans=sol.waysToChange(n);
    DBG(ans);

    system("pause");
    return 0;
}
