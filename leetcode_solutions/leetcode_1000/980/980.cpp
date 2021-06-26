#include "utils.h"

class Solution {
    int m,n,ans=0,fail=0;
    pair<int,int>begin;
    bool visited[20][20]={0};
    void dfs(int i,int j,vvi&grid,int cnt){
        visited[i][j]=true;
        if(grid[i][j]==2)ans+=cnt==m*n-fail;
        else{
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&grid[ii][jj]>=0&&!visited[ii][jj]){
                    dfs(ii,jj,grid,cnt+1);
                }
            }
        }
        visited[i][j]=false;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        REP(i,m){
            REP(j,n){
                if(grid[i][j]==1)begin={i,j};
                else if(grid[i][j]<0)fail++;
            }
        }
        dfs(begin.first,begin.second,grid,1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]");
    auto ans=sol.uniquePathsIII(grid);
    DBG(ans);

    system("pause");
    return 0;
}
