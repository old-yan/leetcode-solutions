#include "Union.h"
#include "utils.h"

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        bool dp[m][n][4];
        memset(dp,0,sizeof(dp));
        REP(i,m)REP(j,n){
            if(grid[i][j]==1)dp[i][j][0]=dp[i][j][2]=true;
            else if(grid[i][j]==2)dp[i][j][1]=dp[i][j][3]=true;
            else if(grid[i][j]==3)dp[i][j][2]=dp[i][j][3]=true;
            else if(grid[i][j]==4)dp[i][j][0]=dp[i][j][3]=true;
            else if(grid[i][j]==5)dp[i][j][1]=dp[i][j][2]=true;
            else if(grid[i][j]==6)dp[i][j][1]=dp[i][j][0]=true;
        }
        Union u(m*n);
        REP(i,m)REP(j,n)REP(k,4)if(dp[i][j][k]){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&dp[ii][jj][(k+2)%4]){
                u.unite(i*n+j,ii*n+jj);
            }
        }
        return u.same(0,m*n-1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[2,4,3],[6,5,2]]");
    auto ans=sol.hasValidPath(grid);
    DBG(ans);

    system("pause");
    return 0;
}
