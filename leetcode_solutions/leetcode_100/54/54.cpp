#include "utils.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vi ans;
        int i=0,j=0,idx=0,m=matrix.size(),n=matrix[0].size();
        bool visited[m][n];
        memset(visited,0,sizeof(visited));
        while(ans.size()<m*n){
            ans.pb(matrix[i][j]);
            visited[i][j]=true;
            int ii=i+di[idx],jj=j+dj[idx];
            if(ii<0||ii>=m||jj<0||jj>=n||visited[ii][jj]){
                idx=(idx+3)%4;
                ii=i+di[idx],jj=j+dj[idx];
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

    vvi matrix{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    auto ans=sol.spiralOrder(matrix);
    DBGV(ans);

    system("pause");
    return 0;
}
