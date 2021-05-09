#include "utils.h"

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        ll dp[m][n][2];
        REP(i,m)REP(j,n){
            if(!grid[i][j])dp[i][j][0]=dp[i][j][1]=0;
            else if(grid[i][j]>0){
                if(i){
                    dp[i][j][0]=j?min(dp[i-1][j][0],dp[i][j-1][0])*grid[i][j]:dp[i-1][j][0]*grid[i][j];
                    dp[i][j][1]=j?max(dp[i-1][j][1],dp[i][j-1][1])*grid[i][j]:dp[i-1][j][1]*grid[i][j];
                }
                else{
                    dp[i][j][0]=j?dp[i][j-1][0]*grid[i][j]:grid[i][j];
                    dp[i][j][1]=j?dp[i][j-1][1]*grid[i][j]:grid[i][j];
                }
            }
            else{
                if(i){
                    dp[i][j][1]=j?min(dp[i-1][j][0],dp[i][j-1][0])*grid[i][j]:dp[i-1][j][0]*grid[i][j];
                    dp[i][j][0]=j?max(dp[i-1][j][1],dp[i][j-1][1])*grid[i][j]:dp[i-1][j][1]*grid[i][j];
                }
                else{
                    dp[i][j][1]=j?dp[i][j-1][0]*grid[i][j]:grid[i][j];
                    dp[i][j][0]=j?dp[i][j-1][1]*grid[i][j]:grid[i][j];
                }
            }
        }
        return dp[m-1][n-1][1]>=0?dp[m-1][n-1][1]%MOD:-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]");
    auto ans=sol.maxProductPath(grid);
    DBG(ans);

    system("pause");
    return 0;
}
