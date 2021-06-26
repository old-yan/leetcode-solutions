#include "utils.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        REP(i,n/2){
            REP(j,n-i*2-1){
                int a=matrix[i][i+j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=a;
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[1,2,3],[4,5,6],[7,8,9]]");
    sol.rotate(matrix);
    DBGVV(matrix);

    system("pause");
    return 0;
}
