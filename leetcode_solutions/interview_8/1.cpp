#include "utils.h"

class Solution {
public:
    int waysToStep(int n) {
        static ll dp[1000001]={0};
        if(!dp[0]){
            dp[0]=1,dp[1]=1,dp[2]=2;
            FOR(i,3,1000001){
                dp[i]=(dp[i-3]+dp[i-2]+dp[i-1])%MOD;
            }
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    auto ans=sol.waysToStep(n);
    DBG(ans);

    system("pause");
    return 0;
}
