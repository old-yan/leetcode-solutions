#include "utils.h"

class Solution {
    const int units[7]={1,3,9,27,81,243,729};
    const int values[3]={0,120,40};
    const int relates[3][3]={
        {0,0,0},
        {0,-60,-10},
        {0,-10,40}
    };
public:
    typedef tuple<int,int,int,int,int> tii;
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int dp[m+1][n][units[n]][introvertsCount+2][extrovertsCount+2];
        memset(dp,0x80,sizeof(dp));
        dp[0][n-1][0][introvertsCount][extrovertsCount]=0;
        REP(i,m)REP(j,n)REP(mask,units[n])REP(intro,introvertsCount+1)REP(extro,extrovertsCount+1){
            if(j){
                int cur=mask%3,left=mask/3%3;
                REP(up,3){
                    chmax(dp[i+1][j][mask][intro][extro],dp[i+1][j-1][mask/3+units[n-1]*up][intro+(cur==1)][extro+(cur==2)]+values[cur]+relates[cur][left]+relates[cur][up]);
                }
            }
            else{
                int cur=mask%3;
                REP(up,3){
                    chmax(dp[i+1][j][mask][intro][extro],dp[i][n-1][mask/3+units[n-1]*up][intro+(cur==1)][extro+(cur==2)]+values[cur]+relates[cur][up]);
                }
            }
        }
        return *max_element(dp[m][n-1][0][0],dp[m][n-1][units[n]][0]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=3;
    int n=1;
    int introvertsCount=2;
    int extrovertsCount=1;
    auto ans=sol.getMaxGridHappiness(m,n,introvertsCount,extrovertsCount);
    DBG(ans);

    system("pause");
    return 0;
}
