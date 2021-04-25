#include "utils.h"

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(matrix[i][j]==1){
                    if(dp[i][j+1]!=dp[i+1][j])dp[i+1][j+1]=min(dp[i+1][j],dp[i][j+1])+1;
                    else dp[i+1][j+1]=min(dp[i+1][j],dp[i][j])+1;
                }
                else dp[i+1][j+1]=0;
                ans+=dp[i+1][j+1];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[0,1,1,1],[1,1,1,1],[0,1,1,1]]");
    auto ans=sol.countSquares(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
