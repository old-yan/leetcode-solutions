#include "utils.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        REPR(i,m-1){
            REPR(j,n-1){
                if(i==m-1||j==n-1)dp[i][j]=1;
                else{
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=3,n=7;
    auto ans=sol.uniquePaths(m,n);
    DBG(ans);

    system("pause");
    return 0;
}
