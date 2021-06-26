#include "utils.h"

class Solution {
public:
    int twoEggDrop(int n) {
        int dp[n+1][3];
        dp[0][0]=dp[0][1]=dp[0][2]=0;
        FOR(i,1,n+1){
            dp[i][0]=dp[i][1]=dp[i][2]=0x3f3f3f3f;
            FOR(j,1,i+1){
                chmin(dp[i][1],max(dp[i-1][0],dp[j-i][1]));
                chmin(dp[i][2],max(dp[i-1][1],dp[j-i][2]));
            }
        }
        return dp[n][2];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    auto ans=sol.twoEggDrop(n);
    DBG(ans);

    system("pause");
    return 0;
}
