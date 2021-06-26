#include "utils.h"

class Solution {
public:
    vector<double> dicesProbability(int n) {
        double dp[n+1][n*6+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        FOR(i,1,n+1){
            FOR(j,1,n*6+1){
                dp[i][j]=0;
                FOR(k,1,7)if(j-k>=0){
                    dp[i][j]+=dp[i-1][j-k]/6;
                }
            }
        }
        return vector<double>(dp[n]+n,dp[n]+n*6+1);;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    auto ans=sol.dicesProbability(n);
    DBGV(ans);

    system("pause");
    return 0;
}
