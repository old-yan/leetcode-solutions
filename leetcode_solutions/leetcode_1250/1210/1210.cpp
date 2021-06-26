#include "utils.h"

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n][2];
        memset(dp,0x3f,sizeof(dp));
        dp[0][1][0]=0;
        queue<tuple<int,int,int,int>>Q;
        Q.emplace(0,0,1,0);
        while(Q.size()){
            auto [dis,i,j,k]=Q.front();
            Q.pop();
            if(dis!=dp[i][j][k])continue;
            if(k==0){
                if(j+1<n&&!grid[i][j+1]&&chmin(dp[i][j+1][0],dis+1)){
                    Q.emplace(dis+1,i,j+1,0);
                }
                if(i+1<m&&!grid[i+1][j-1]&&!grid[i+1][j]){
                    if(chmin(dp[i+1][j][0],dis+1)){
                        Q.emplace(dis+1,i+1,j,0);
                    }
                    if(chmin(dp[i+1][j-1][1],dis+1)){
                        Q.emplace(dis+1,i+1,j-1,1);
                    }
                }
            }
            else{
                if(i+1<m&&!grid[i+1][j]&&chmin(dp[i+1][j][1],dis+1)){
                    Q.emplace(dis+1,i+1,j,1);
                }
                if(j+1<n&&!grid[i-1][j+1]&&!grid[i][j+1]){
                    if(chmin(dp[i][j+1][1],dis+1)){
                        Q.emplace(dis+1,i,j+1,1);
                    }
                    if(chmin(dp[i-1][j+1][0],dis+1)){
                        Q.emplace(dis+1,i-1,j+1,0);
                    }
                }
            }
        }
        return dp[m-1][n-1][0]==0x3f3f3f3f?-1:dp[m-1][n-1][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,0,0,0,0,1],[1,1,0,0,1,0],[0,0,0,0,1,1],[0,0,1,0,1,0],[0,1,1,0,0,0],[0,1,1,0,0,0]]");
    auto ans=sol.minimumMoves(grid);
    DBG(ans);

    system("pause");
    return 0;
}
