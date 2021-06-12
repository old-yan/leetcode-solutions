#include "utils.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vi ans;
        int m=matrix.size();
        if(!m)return ans;
        int n=matrix[0].size();
        bool visited[m][n];
        memset(visited,0,sizeof(visited));
        int i=0,j=0,k=0;
        while(ans.size()<m*n){
            ans.pb(matrix[i][j]);
            visited[i][j]=true;
            int ii=i+di[k],jj=j+dj[k];
            if(!VALID||visited[ii][jj]){
                k=(k+3)%4;
                ii=i+di[k],jj=j+dj[k];
            }
            i=ii,j=jj;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[1,2,3],[4,5,6],[7,8,9]]");
    auto ans=sol.spiralOrder(matrix);
    DBGV(ans);

    system("pause");
    return 0;
}
