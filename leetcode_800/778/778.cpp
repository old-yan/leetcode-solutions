#include "Union.h"
#include "utils.h"

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N=grid.size();
        int m=N,n=N;
        pair<int,int>p[N*N];
        REP(i,N){
            REP(j,N){
                p[grid[i][j]]=make_pair(i,j);
            }
        }
        Union u(N*N);
        REP(idx,N*N){
            auto [i,j]=p[idx];
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&grid[ii][jj]<=grid[i][j])u.unite(i*N+j,ii*N+jj);
            }
            if(u.same(0,N*N-1))return grid[i][j];
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,2],[1,3]]");
    auto ans=sol.swimInWater(grid);
    DBG(ans);

    system("pause");
    return 0;
}
