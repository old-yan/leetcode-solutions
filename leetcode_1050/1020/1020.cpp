#include "Union.h"
#include "utils.h"

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        Union u(m*n+1);
        REP(i,m){
            REP(j,n){
                if(!i||!j||i==m-1||j==n-1)u.unite(i*n+j,m*n);
                if(!grid[i][j])continue;
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&grid[ii][jj]){
                        u.unite(i*n+j,ii*n+jj);
                    }
                }
            }
        }
        int ans=0;
        REP(i,m){
            REP(j,n){
                if(grid[i][j]&&u.Find(i*n+j)!=0)ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]");
    auto ans=sol.numEnclaves(grid);
    DBG(ans);

    system("pause");
    return 0;
}
