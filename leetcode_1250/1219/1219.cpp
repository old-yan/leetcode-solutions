#include "utils.h"

int dp[1<<25]={0};
class Solution {
    vector<pair<int,int>>points;
    bool visited[15][15]={0};
    vvi grid;
    int m,n,cnt,ans=0;
    void dfs(int i,int j,int money){
        visited[i][j]=true;
        chmax(ans,money);
        REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&grid[ii][jj]&&!visited[ii][jj]){
                dfs(ii,jj,money+grid[ii][jj]);
            }
        }
        visited[i][j]=false;
    }
public:
    int getMaximumGold(vector<vector<int>>&_grid) {
        grid=_grid;m=grid.size(),n=grid[0].size(),cnt=0;
        REP(i,m){
            REP(j,n){
                if(grid[i][j]){
                    dfs(i,j,grid[i][j]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,6,0],[5,8,7],[0,9,0]]");
    auto ans=sol.getMaximumGold(grid);
    DBG(ans);

    system("pause");
    return 0;
}
