#include "utils.h"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        REPR(i,n-2){
            matrix[i][0]+=min(matrix[i+1][0],matrix[i][1]);
            matrix[i][n-1]+=min(matrix[i+1][n-2],matrix[i+1][n-1]);
            FOR(j,1,n-1){
                matrix[i][j]+=min(matrix[i+1][j],min(matrix[i+1][j-1],matrix[i+1][j+1]));
            }
        }
        return *min_element(ALL(matrix[0]));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[2,1,3],[6,5,4],[7,8,9]]");
    auto ans=sol.minFallingPathSum(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
