#include "utils.h"

class Solution {
public:
    //按照数值从大到小的顺序，进行放置
    //每次放置时，可以分成两种情况：放到最前面，使得“看到数”+1；或者放到后面的某个位置，“看到数”不变
    int rearrangeSticks(int n, int k) {
        //dp[i][j]表示：将数字[i,n]放完之后，“看到数”为j，有多少种方案
        ll dp[n+1][k+2];
        memset(dp,0,sizeof(dp));
        //将数字[n,n]放完之后，“看到数”只能为1，方案数为1
        dp[n][1]=1;
        //从n-1到1，逐个放置
        FORR(i,n-1,1){
            //dp[i][j]有两种转移来源：
            //  如果将i放前面，那就从dp[i+1][j-1]转移而来
            //  如果将i放后面，那就从dp[i+1][j]转移而来，注意后面的位置不唯一，i随便选个位置放都行
            FOR(j,1,k+1){
                dp[i][j]=(dp[i+1][j]*(n-i-1)+dp[i+1][j-1])%MOD;
            }
        }
        return dp[1][k];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=20;
    int k=11;
    auto ans=sol.rearrangeSticks(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
