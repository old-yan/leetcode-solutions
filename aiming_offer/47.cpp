#include "utils.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        REP(i,m)REP(j,n){
            dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])+grid[i][j];
        }
        return dp[m][n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,3,1],[1,5,1],[4,2,1]]");
    auto ans=sol.maxValue(grid);
    DBG(ans);

    system("pause");
    return 0;
}
