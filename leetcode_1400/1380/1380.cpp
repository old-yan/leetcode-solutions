#include "utils.h"

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vi rowMin(m,INT_MAX),colMax(n,INT_MIN);
        REP(i,m){
            rowMin[i]=*min_element(ALL(matrix[i]));
            REP(j,n)chmax(colMax[j],matrix[i][j]);
        }
        vi ans;
        REP(i,m)REP(j,n)if(matrix[i][j]==rowMin[i]&&matrix[i][j]==colMax[j]){
            ans.pb(matrix[i][j]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[3,7,8],[9,11,13],[15,16,17]]");
    auto ans=sol.luckyNumbers(matrix);
    DBGV(ans);

    system("pause");
    return 0;
}
