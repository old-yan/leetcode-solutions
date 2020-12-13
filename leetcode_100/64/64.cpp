#include "utils.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        ll dp[m][n];
        memset(dp,0x3f,sizeof(dp));
        REPR(i,m-1){
            REPR(j,n-1){
                if(i==m-1&&j==n-1)dp[i][j]=grid[i][j];
                if(i<m-1)chmin(dp[i][j],grid[i][j]+dp[i+1][j]);
                if(j<n-1)chmin(dp[i][j],grid[i][j]+dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid{{1,3,1},{1,5,1},{4,2,1}};
    auto ans=sol.minPathSum(grid);
    DBG(ans);

    system("pause");
    return 0;
}
