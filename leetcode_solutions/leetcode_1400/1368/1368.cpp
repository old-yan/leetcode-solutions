#include "utils.h"

class Solution {
    int mapping[5]={-1,0,2,3,1};
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m][n];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
        deque<tuple<int,int,int>>Q;
        Q.emplace_back(0,0,0);
        while(Q.size()){
            auto [curdis,i,j]=Q.front();
            Q.pop_front();
            if(i==m-1&&j==n-1)return curdis;
            if(curdis!=dp[i][j])continue;
            int dir=mapping[grid[i][j]];
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID)continue;
                if(k==dir){
                    if(chmin(dp[ii][jj],curdis))Q.emplace_front(curdis,ii,jj);
                }
                else{
                    if(chmin(dp[ii][jj],curdis+1))Q.emplace_back(curdis+1,ii,jj);
                }
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]");
    auto ans=sol.minCost(grid);
    DBG(ans);

    system("pause");
    return 0;
}
