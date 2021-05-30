#include "Union.h"
#include "Graph.h"
#include "utils.h"

UndirectedGraph<>udg;
class Solution {
    int m,n,water=0;
    bool inone(vvi&grid){
        m=grid.size(),n=grid[0].size();
        Union u(m*n);
        REP(i,m)REP(j,n){
            if(grid[i][j])REP(k,2){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID||!grid[ii][jj])continue;
                u.unite(i*n+j,ii*n+jj);
            }
            else water++;
        }
        return u.group-water==1;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        if(!inone(grid)||water==m*n)return 0;
        if(water==m*n-1)return 1;
        udg.reset(m*n);
        REP(i,m)REP(j,n)if(grid[i][j])REP(k,2){
            int ii=i+di[k],jj=j+dj[k];
            if(!VALID||!grid[ii][jj])continue;
            udg.addEdge(i*n+j,ii*n+jj);
        }
        utj.solve(udg);
        REP(i,m)REP(j,n)if(grid[i][j]&&utj.isCut[i*n+j])return 1;
        return 2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,1,1,0],[0,1,1,0],[0,0,0,0]]");
    auto ans=sol.minDays(grid);
    DBG(ans);

    system("pause");
    return 0;
}
