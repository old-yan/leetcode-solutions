#include "Union.h"
#include "Graph.h"
#include "utils.h"

Union u(20000);
FlowNetwork<int>fn;
class Solution {
    int source,target=-1,P=-1;
public:
    int guardCastle(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        fn.reset(m*n);
        u.reset();
        REP(i,m)REP(j,n){
            if(grid[i][j]=='C')source=i*n+j;
            else if(grid[i][j]=='S'){
                if(target<0)target=i*n+j;
                else u.unite(target,i*n+j);
            }
            else if(grid[i][j]=='P'){
                if(P<0)P=i*n+j;
                else u.unite(P,i*n+j);
            }
        }
        REP(i,m)REP(j,n)if(grid[i][j]!='.'&&grid[i][j]!='#')REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&grid[ii][jj]!='.'&&grid[ii][jj]!='#')u.unite(i*n+j,ii*n+jj);
        }
        if(u.same(source,target))return -1;
        REP(i,m)REP(j,n)if(grid[i][j]!='#')REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID&&grid[ii][jj]!='#'){
                fn.addEdge(u.Find(i*n+j),u.Find(ii*n+jj),1);
            }
        }
        return ISAP(u.Find(source),u.Find(target),fn);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>grid{
        "S.C.P#P.", ".....#.S"
    };
    auto ans=sol.guardCastle(grid);
    DBG(ans);

    system("pause");
    return 0;
}
