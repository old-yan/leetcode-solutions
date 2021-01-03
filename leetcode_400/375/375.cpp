#include "utils.h"

class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n][n];
        memset(dp,0x3f,sizeof(dp));
        REP(i,n){
            REP(j,n-i+1){
                if(!i)dp[j][j+i]=0;
                else if(i==1)dp[j][j+i]=j+1;
                else{
                    int&a=dp[j][j+i];
                    FOR(k,j+1,j+i){
                        chmin(a,int(k+1)+max(dp[j][k-1],dp[k+1][j+i]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.getMoneyAmount(n);
    DBG(ans);

    system("pause");
    return 0;
}
