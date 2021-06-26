#include "Union.h"
#include "utils.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        Union u(m*n);
        REP(i,m){
            REP(j,n){
                if(!grid[i][j])continue;
                REP(k,2){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&grid[ii][jj])u.unite(i*n+j,ii*n+jj);
                }
            }
        }
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(grid[i][j]&&u.Find(i*n+j)==i*n+j){
                    chmax(ans,u.size[i*n+j]);
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

    vvi grid{
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    auto ans=sol.maxAreaOfIsland(grid);
    DBG(ans);

    system("pause");
    return 0;
}
