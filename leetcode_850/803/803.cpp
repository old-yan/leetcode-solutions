#include "Union.h"
#include "utils.h"

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m=grid.size(),n=grid[0].size();
        for(auto&hit:hits){
            grid[hit[0]][hit[1]]*=-1;
        }
        Union u(m*n+n);
        FOR(j,1,n)u.unite(0,j);
        REP(i,m){
            REP(j,n){
                if(grid[i][j]!=1)continue;
                REP(k,2){
                    int ii=i+di[k],jj=j+dj[k];
                    if(ii<0||(VALID&&grid[ii][jj]==1)){
                        u.unite(i*n+n+j,ii*n+n+jj);
                    }
                }
            }
        }
        vi ans(hits.size(),0);
        int size=u.size[0];
        REPR(i,hits.size()-1){
            grid[hits[i][0]][hits[i][1]]*=-1;
            if(!grid[hits[i][0]][hits[i][1]])continue;
            REP(k,4){
                int ii=hits[i][0]+di[k],jj=hits[i][1]+dj[k];
                if(ii<0||(VALID&&grid[ii][jj]==1)){
                    u.unite(hits[i][0]*n+n+hits[i][1],ii*n+n+jj);
                }
            }
            if(u.size[0]>size){
                ans[i]=u.size[0]-size-1;
                size=u.size[0];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[1,0,0,0],[1,1,1,0]]");
    vvi hits=makevvi("[[1,0]]");
    auto ans=sol.hitBricks(grid,hits);
    DBGV(ans);

    system("pause");
    return 0;
}
