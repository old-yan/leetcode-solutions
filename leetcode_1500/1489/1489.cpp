#include "Union.h"
#include "Tarjan.h"
#include "utils.h"

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        Union u(n);
        REP(i,edges.size())edges[i].pb(i);
        sort(ALL(edges),[](auto&x,auto&y){return x[2]<y[2];});
        bool isBridge[edges.size()];
        memset(isBridge,0,sizeof(isBridge));
        vvi ans(2);
        for(int i=0,j=0;i<edges.size();){
            for(j=i;j<edges.size()&&edges[j][2]==edges[i][2];j++){
                edges[j][0]=u.Find(edges[j][0]);
                edges[j][1]=u.Find(edges[j][1]);
            }
            tarjanBridge(edges.begin()+i,edges.begin()+j,isBridge+i).findBridge();
            FOR(k,i,j)if(edges[k][0]!=edges[k][1]){
                if(isBridge[k])ans[0].pb(edges[k][3]);
                else ans[1].pb(edges[k][3]);
            }
            while(i<j){
                u.unite(edges[i][0],edges[i++][1]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vvi edges=makevvi("[[0,1,1],[1,2,1],[2,3,1],[0,3,1]]");
    auto ans=sol.findCriticalAndPseudoCriticalEdges(n,edges);
    DBGVV(ans);

    system("pause");
    return 0;
}
