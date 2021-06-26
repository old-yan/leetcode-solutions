#include "utils.h"

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m+1][n];
        memset(dp,0xff,sizeof(dp));
        iota(dp[m],dp[m+1],0);
        REPR(i,m-1){
            REP(j,n){
                if(grid[i][j]==1&&j+1<n&&grid[i][j+1]==1){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(grid[i][j]==-1&&j-1>=0&&grid[i][j-1]==-1){
                    dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        return vi(dp[0],dp[1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]");
    auto ans=sol.findBall(grid);
    DBGV(ans);

    system("pause");
    return 0;
}
