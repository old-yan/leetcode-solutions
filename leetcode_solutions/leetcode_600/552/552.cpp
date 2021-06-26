#include "utils.h"

class Solution {
public:
    int checkRecord(int n) {
        ll dp[n][2][3];
        #define a(i,j,k) (i>=0?dp[i][j][k]:(j==0&&k==0))
        REP(i,n){
            dp[i][0][0]=(a(i-1,0,0)+a(i-1,0,1)+a(i-1,0,2))%MOD;
            dp[i][0][1]=a(i-1,0,0);
            dp[i][0][2]=a(i-1,0,1);
            dp[i][1][0]=(a(i-1,0,0)+a(i-1,0,1)+a(i-1,0,2)+a(i-1,1,0)+a(i-1,1,1)+a(i-1,1,2))%MOD;
            dp[i][1][1]=a(i-1,1,0);
            dp[i][1][2]=a(i-1,1,1);
        }
        return (dp[n-1][0][0]+dp[n-1][0][1]+dp[n-1][0][2]+dp[n-1][1][0]+dp[n-1][1][1]+dp[n-1][1][2])%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    auto ans=sol.checkRecord(n);
    DBG(ans);

    system("pause");
    return 0;
}
