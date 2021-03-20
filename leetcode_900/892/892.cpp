#include "utils.h"

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(!grid[i][j])continue;
                ans+=2;
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID){
                        if(grid[ii][jj]<grid[i][j])ans+=grid[i][j]-grid[ii][jj];
                    }
                    else ans+=grid[i][j];
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,2],[3,4]]");
    auto ans=sol.surfaceArea(grid);
    DBG(ans);

    system("pause");
    return 0;
}
