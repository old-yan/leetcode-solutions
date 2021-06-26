#include "utils.h"

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        int sum[m+1][n+1];
        memset(sum,0,sizeof(sum));
        REP(i,m)REP(j,n)sum[i+1][j+1]=mat[i][j];
        REP(i,m)REP(j,n)sum[i+1][j+1]+=sum[i+1][j];
        REP(i,m)REP(j,n)sum[i+1][j+1]+=sum[i][j+1];
        vvi ans(m,vi(n));
        REP(i,m)REP(j,n){
            int r1=max(0,int(i)-k),c1=max(0,int(j)-k);
            int r2=min(m-1,int(i)+k),c2=min(n-1,int(j)+k);
            ans[i][j]=sum[r2+1][c2+1]+sum[r1][c1]-sum[r1][c2+1]-sum[r2+1][c1];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,2,3],[4,5,6],[7,8,9]]");
    int k=2;
    auto ans=sol.matrixBlockSum(mat,k);
    DBGVV(ans);

    system("pause");
    return 0;
}
