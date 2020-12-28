#include "utils.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        int dp[m][n];
        REPR(i,m-1){
            REPR(j,n-1){
                if(i==m-1&&j==n-1)dp[i][j]=max(1,1-dungeon[i][j]);
                else if(i==m-1)dp[i][j]=max(1,dp[i][j+1]-dungeon[i][j]);
                else if(j==n-1)dp[i][j]=max(1,dp[i+1][j]-dungeon[i][j]);
                else dp[i][j]=max(1,min(dp[i][j+1],dp[i+1][j])-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi dungeon{{-2,-3,3},{-5,-10,1},{10,30,-5}};
    auto ans=sol.calculateMinimumHP(dungeon);
    DBG(ans);

    system("pause");
    return 0;
}
