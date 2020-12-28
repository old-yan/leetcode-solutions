#include "utils.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int dp[m][n];
        #define a(i,j) (i<0||j<0?0:dp[i][j])
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(matrix[i][j]=='0')dp[i][j]=0;
                else{
                    if(a(i-1,j)==a(i,j-1))
                        dp[i][j]=min(a(i-1,j)+1,a(i-1,j-1)+1);
                    else
                        dp[i][j]=min(a(i-1,j)+1,a(i,j-1)+1);
                }
                chmax(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<char>>matrix{
        {'1','0','1','0'},
        {'1','0','1','1'},
        {'1','0','1','1'},
        {'1','1','1','1'}
    };
    auto ans=sol.maximalSquare(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
