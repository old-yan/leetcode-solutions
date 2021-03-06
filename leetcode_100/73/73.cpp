#include "utils.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstrow=0,firstcol=0;
        int m=matrix.size(),n=matrix[0].size();
        REP(i,m)if(matrix[i][0]==0)firstcol=1;
        REP(j,n)if(matrix[0][j]==0)firstrow=1;
        FOR(i,1,m){
            FOR(j,1,n){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        FOR(i,1,m){
            if(matrix[i][0]==0){
                REP(j,n)matrix[i][j]=0;
            }
        }
        FOR(j,1,n){
            if(matrix[0][j]==0){
                REP(i,m)matrix[i][j]=0;
            }
        }
        if(firstrow)REP(j,n)matrix[0][j]=0;
        if(firstcol)REP(i,m)matrix[i][0]=0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    sol.setZeroes(matrix);
    DBGVV(matrix);

    system("pause");
    return 0;
}
