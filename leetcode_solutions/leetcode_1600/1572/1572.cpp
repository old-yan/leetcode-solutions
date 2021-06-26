#include "utils.h"

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int sum=0;
        REP(i,m)REP(j,n){
            if(i==j||i+j==m-1)sum+=mat[i][j];
        }
        return sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,2,3],[4,5,6],[7,8,9]]");
    auto ans=sol.diagonalSum(mat);
    DBG(ans);

    system("pause");
    return 0;
}
