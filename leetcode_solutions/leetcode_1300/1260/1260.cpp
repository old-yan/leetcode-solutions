#include "utils.h"

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vvi ans(m,vi(n));
        REP(i,m){
            REP(j,n){
                int l=(i*n+j+k)%(m*n);
                ans[l/n][l%n]=grid[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,2,3],[4,5,6],[7,8,9]]");
    int k=1;
    auto ans=sol.shiftGrid(grid,k);
    DBGVV(ans);

    system("pause");
    return 0;
}
