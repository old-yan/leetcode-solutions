#include "utils.h"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>&matrix) {
        int m=matrix.size();
        if(!m)return 0;
        int n=matrix[0].size();
        int bigger[m][n];
        int dp[m][n];
        memset(bigger,0,sizeof(bigger));
        memset(dp,0,sizeof(dp));
        queue<pair<int,int>>Q;
        REP(i,m){
            REP(j,n){
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&matrix[ii][jj]>matrix[i][j])bigger[i][j]++;
                }
                if(!bigger[i][j]){
                    Q.emplace(i,j);
                    dp[i][j]=1;
                }
            }
        }
        int ans=0;
        while(int l=Q.size()){
            while(l--){
                auto p=Q.front();
                Q.pop();
                int i=p.first,j=p.second;
                chmax(ans,dp[i][j]);
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&matrix[ii][jj]<matrix[i][j]&&!--bigger[ii][jj]){
                        dp[ii][jj]=dp[i][j]+1;
                        Q.emplace(ii,jj);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {9,9,4},
        {6,6,8},
        {2,1,1}
    };
    auto ans=sol.longestIncreasingPath(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
