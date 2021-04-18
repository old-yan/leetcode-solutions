#include "Union.h"
#include "utils.h"

class Solution {
    bool isWall[50][50]={0};
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m=grid.size(),n=grid[0].size();
        Union u(m*n);
        REP(i,m){
            REP(j,n){
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&grid[i][j]==grid[ii][jj])u.unite(i*n+j,ii*n+jj);
                }
            }
        }
        int now=u.Find(r0*n+c0);
        REP(i,m){
            REP(j,n){
                if(u.Find(i*n+j)!=now)continue;
                REP(k,4){
                    int ii=i+di[k],jj=j+dj[k];
                    if(VALID&&u.Find(ii*n+jj)==now)continue;
                    isWall[i][j]=true;
                    break;
                }
                if(isWall[i][j])grid[i][j]=color;
            }
        }
        return grid;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,1],[1,2]]");
    int r0=0;
    int c0=0;
    int color=3;
    auto ans=sol.colorBorder(grid,r0,c0,color);
    DBGVV(ans);

    system("pause");
    return 0;
}
