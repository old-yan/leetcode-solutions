#include "utils.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        bool row[m],col[n];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        REP(i,m)REP(j,n){
            if(!matrix[i][j]){
                row[i]=col[j]=true;
            }
        }
        REP(i,m)REP(j,n)if(row[i]||col[j]){
            matrix[i][j]=0;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[1,1,1],[1,0,1],[1,1,1]]");
    sol.setZeroes(matrix);
    DBGVV(matrix);

    system("pause");
    return 0;
}
