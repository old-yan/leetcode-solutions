#include "utils.h"

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n][n];
        memset(dp,0x80,sizeof(dp));
        dp[0][0][n-1]=grid[0][0]+grid[0][n-1];
        FOR(r,1,m){
            REP(c1,n){
                FOR(c2,c1,n){
                    for(int j:{c1-1,c1,c1+1}){
                        for(int k:{c2-1,c2,c2+1}){
                            if(j>=0&&j<n&&k>=0&&k<n&&j<=k)chmax(dp[r][c1][c2],dp[r-1][j][k]);
                        }
                    }
                    dp[r][c1][c2]+=c1==c2?grid[r][c1]:grid[r][c1]+grid[r][c2];
                }
            }
        }
        return *max_element(dp[m-1][0],dp[m][0]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[3,1,1],[2,5,1],[1,5,5],[2,1,1]]");
    auto ans=sol.cherryPickup(grid);
    DBG(ans);

    system("pause");
    return 0;
}
