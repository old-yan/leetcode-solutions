#include "utils.h"

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vi rowmax(m,0),colmax(n,0);
        REP(i,m){
            REP(j,n){
                chmax(rowmax[i],grid[i][j]);
                chmax(colmax[j],grid[i][j]);
            }
        }
        int ans=0;
        REP(i,m){
            REP(j,n){
                ans+=min(rowmax[i],colmax[j])-grid[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]");
    auto ans=sol.maxIncreaseKeepingSkyline(grid);
    DBG(ans);

    system("pause");
    return 0;
}
