#include "Union.h"
#include "Graph.h"
#include "utils.h"

UndirectedGraph<>udg;
Union u(100);
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        u.reset();
        vi idxes(m);
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return edges[x][2]<edges[y][2];});
        vvi ans(2);
        for(int i=0,j=0;i<m;){
            unordered_map<int,int>M;
            for(j=i;j<m&&edges[idxes[j]][2]==edges[idxes[i]][2];j++){
                edges[idxes[j]][0]=u.Find(edges[idxes[j]][0]);
                if(!M.count(edges[idxes[j]][0]))M[edges[idxes[j]][0]]=M.size();
                edges[idxes[j]][1]=u.Find(edges[idxes[j]][1]);
                if(!M.count(edges[idxes[j]][1]))M[edges[idxes[j]][1]]=M.size();
            }
            udg.reset(M.size());
            FOR(k,i,j){
                udg.addEdge(M[edges[idxes[k]][0]],M[edges[idxes[k]][1]]);
            }
            utj.solve(udg);
            FOR(k,i,j)if(edges[idxes[k]][0]!=edges[idxes[k]][1]){
                if(utj.isBridge(M[edges[idxes[k]][0]],M[edges[idxes[k]][1]]))ans[0].pb(idxes[k]);
                else ans[1].pb(idxes[k]);
            }
            while(i<j){
                u.unite(edges[idxes[i]][0],edges[idxes[i]][1]);
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vvi edges=makevvi("[[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]");
    auto ans=sol.findCriticalAndPseudoCriticalEdges(n,edges);
    DBGVV(ans);

    system("pause");
    return 0;
}
