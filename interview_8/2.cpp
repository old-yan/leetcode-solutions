#include "utils.h"

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0])return {};
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        bool dp[m][n];
        pair<int,int>from[m][n];
        memset(dp,0,sizeof(dp));
        memset(from,0xff,sizeof(from));
        dp[0][0]=true;
        queue<pair<int,int>>Q;
        Q.emplace(0,0);
        while(Q.size()){
            auto [i,j]=Q.front();
            Q.pop();
            for(int k:{0,3}){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&!obstacleGrid[ii][jj]&&!dp[ii][jj]){
                    dp[ii][jj]=true;
                    from[ii][jj]={i,j};
                    Q.emplace(ii,jj);
                }
            }
            if(dp[m-1][n-1])break;
        }
        vvi ans;
        if(!dp[m-1][n-1])return ans;
        int i=m-1,j=n-1;
        do{
            ans.pb({i,j});
            tie(i,j)=from[i][j];
        }while(i>=0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi obstableGrid=makevvi("[[0,0,0],[0,1,0],[0,0,0]]");
    auto ans=sol.pathWithObstacles(obstableGrid);
    DBGVV(ans);

    system("pause");
    return 0;
}
