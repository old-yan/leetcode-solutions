#include "Graph/Graph.h"
#include "utils.h"

FlowNetwork<int>fn;
class Solution {
public:
    int domino(int m, int n, vector<vector<int>>& broken) {
        bool bad[m][n];
        memset(bad,0,sizeof(bad));
        for(auto&b:broken){
            bad[b[0]][b[1]]=true;
        }
        fn.reset(m*n+2);
        REP(i,m)REP(j,n)if(!bad[i][j]){
            if((i+j)%2==0)fn.addEdge(m*n,i*n+j,1);
            else fn.addEdge(i*n+j,m*n+1,1);
            REP(k,2){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID||bad[ii][jj])continue;
                if((i+j)%2==0)fn.addEdge(i*n+j,ii*n+jj,1);
                else fn.addEdge(ii*n+jj,i*n+j,1);
            }
        }
        return Dinic(m*n,m*n+1,fn);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    int m=3;
    vvi broken=makevvi("[[0,0],[0,1]]");
    auto ans=sol.domino(n,m,broken);
    DBG(ans);

    system("pause");
    return 0;
}
