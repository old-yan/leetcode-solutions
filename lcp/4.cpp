#include "Graph.h"
#include "utils.h"

BipartiteGraph bpg;
class Solution {
public:
    int domino(int m, int n, vector<vector<int>>& broken) {
        int id[m][n];
        memset(id,0,sizeof(id));
        for(auto&b:broken){
            id[b[0]][b[1]]=-1;
        }
        int num[2]={0};
        REP(i,m)REP(j,n)if(!id[i][j]){
            int k=(i+j)%2;
            id[i][j]=num[k]++;
        }
        bpg.reset(num[0],num[1]);
        REP(i,m)REP(j,n)if(id[i][j]>=0)REP(k,2){
            int ii=i+di[k],jj=j+dj[k];
            if(!VALID||id[ii][jj]<0)continue;
            if((i+j)%2==0)bpg.addEdge(id[i][j],id[ii][jj]);
            else bpg.addEdge(id[ii][jj],id[i][j]);
        }
        return bpg.maxMatch();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    int m=3;
    vvi broken=makevvi("[[1,0],[1,1]]");
    auto ans=sol.domino(n,m,broken);
    DBG(ans);

    system("pause");
    return 0;
}
