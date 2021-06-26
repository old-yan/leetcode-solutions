#include "utils.h"

class Solution {
    int xz[50]={0};
    int yz[50]={0};
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(grid[i][j])ans++;
                chmax(xz[i],grid[i][j]);
                chmax(yz[j],grid[i][j]);
            }
        }
        REP(i,m)ans+=xz[i];
        REP(j,n)ans+=yz[j];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[2,2,2],[2,1,2],[2,2,2]]");
    auto ans=sol.projectionArea(grid);
    DBG(ans);

    system("pause");
    return 0;
}
