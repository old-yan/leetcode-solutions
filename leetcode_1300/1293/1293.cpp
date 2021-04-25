#include "utils.h"

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        int m=grid.size(),n=grid[0].size();
        if(K>=m+n-3)return m+n-2;
        int dp[m][n][K+1];
        memset(dp,0x3f,sizeof(dp));
        queue<tuple<int,int,int,int>>Q;
        dp[0][0][0]=0;
        Q.emplace(0,0,0,0);
        int ans=INT_MAX;
        while(Q.size()&&ans==INT_MAX){
            auto [i,j,step,dis]=Q.front();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID){
                    if(grid[ii][jj]){
                        if(step<K&&chmin(dp[ii][jj][step+1],dis+1)){
                            if(ii==m-1&&jj==n-1)chmin(ans,dis+1);
                            Q.emplace(ii,jj,step+1,dis+1);
                        }
                    }
                    else{
                        if(chmin(dp[ii][jj][step],dis+1)){
                            if(ii==m-1&&jj==n-1)chmin(ans,dis+1);
                            Q.emplace(ii,jj,step,dis+1);
                        }
                    }
                }
            }
        }
        return short(ans);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]]");
    int k=1;
    auto ans=sol.shortestPath(grid,k);
    DBG(ans);

    system("pause");
    return 0;
}
