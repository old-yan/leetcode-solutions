#include "utils.h"

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid.size();
        ll dp[m+n-1][m][m];
        dp[0][m-1][m-1]=grid[0][0];
        FOR(i,1,m+n-1){
            int start=max(int(m-1-i),0);
            int end=min(m-1,int(m+n-2-i));
            FOR(j,start,end+1){
                FOR(k,j,end+1){
                    int r1=m-1-j,c1=i-m+1+j;
                    int r2=m-1-k,c2=i-m+1+k;
                    if(grid[r1][c1]<0||grid[r2][c2]<0)dp[i][j][k]=INT_MIN;
                    else{
                        dp[i][j][k]=INT_MIN;
                        if(c1)chmax(dp[i][j][k],dp[i-1][j][k]);
                        if(r2)chmax(dp[i][j][k],dp[i-1][j+1][k+1]);
                        if(c1&&r2)chmax(dp[i][j][k],dp[i-1][j][k+1]);
                        if(j!=k)chmax(dp[i][j][k],dp[i-1][j+1][k]);
                        dp[i][j][k]+=j==k?grid[r1][c1]:grid[r1][c1]+grid[r2][c2];
                    }
                }
            }
        }
        return max(int(dp[m+n-2][0][0]),0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,1,-1],[1,0,-1],[1,1,1]]");
    auto ans=sol.cherryPickup(grid);
    DBG(ans);

    system("pause");
    return 0;
}
