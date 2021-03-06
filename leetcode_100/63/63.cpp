#include "utils.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int dp[m][n];
        REPR(i,m-1){
            REPR(j,n-1){
                dp[i][j]=0;
                if(obstacleGrid[i][j])continue;
                if(i<m-1)dp[i][j]+=dp[i+1][j];
                if(j<n-1)dp[i][j]+=dp[i][j+1];
                if(i==m-1&&j==n-1)dp[i][j]=1;
            }
        }
        return dp[0][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi obstacleGraid{{0,0,0},{0,1,0},{0,0,0}};
    auto ans=sol.uniquePathsWithObstacles(obstacleGraid);
    DBG(ans);

    system("pause");
    return 0;
}
