#include "Union.h"
#include "utils.h"

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        Union u(m*n+1);
        REP(i,m){
            REP(j,n){
                if(!grid[i][j]){
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(!VALID){
                            u.unite(i*n+j+1,0);
                        }
                        else if(!grid[ii][jj]){
                            u.unite(i*n+j+1,ii*n+jj+1);
                        }
                    }
                }
            }
        }
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(!grid[i][j]&&u.Find(i*n+j+1)==i*n+j+1)ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]");
    auto ans=sol.closedIsland(grid);
    DBG(ans);

    system("pause");
    return 0;
}
