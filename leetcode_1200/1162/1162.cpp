#include "utils.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dist[m][n];
        memset(dist,0x3f,sizeof(dist));
        queue<pair<int,int>>Q;
        REP(i,m){
            REP(j,n){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    Q.emplace(i,j);
                }
            }
        }
        int ans=-1;
        while(Q.size()){
            auto [i,j]=Q.front();
            int dis=dist[i][j];
            if(!grid[i][j])chmax(ans,dis);
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&chmin(dist[ii][jj],dis+1)){
                    Q.emplace(ii,jj);
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

    vvi grid=makevvi("[[1,0,1],[0,0,0],[1,0,1]]");
    auto ans=sol.maxDistance(grid);
    DBG(ans);

    system("pause");
    return 0;
}
