#include "Graph.h"
#include "utils.h"

UndirectedGraph udg;
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        udg.reset(n);
        for(auto&e:edges)udg.addEdge(e[0],e[1],e[2]+1);
        int dist[n];
        dijkstra(0,dist,udg);

        int ans=0;
        for(auto&e:edges){
            int left=max(0,maxMoves-dist[e[0]]);
            int right=max(0,maxMoves-dist[e[1]]);
            ans+=min(e[2],left+right);
        }
        REP(i,n){
            if(dist[i]<=maxMoves)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges=makevvi("[[1,2,5],[0,3,3],[1,3,2],[2,3,4],[0,4,1]]");
    int maxMoves=7;
    int n=5;
    auto ans=sol.reachableNodes(edges,maxMoves,n);
    DBG(ans);

    system("pause");
    return 0;
}
