#include "utils.h"

class Solution {
public:
    int climbStairs(int n) {
        ll dp[1000]={0};
        dp[0]=1;
        REP(i,n){
            dp[i+1]+=dp[i];
            dp[i+2]+=dp[i];
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.climbStairs(n);
    DBG(ans);

    system("pause");
    return 0;
}
