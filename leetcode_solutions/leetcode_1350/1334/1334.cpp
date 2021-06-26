#include "Graph.h"
#include "utils.h"

UndirectedGraph<>udg;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        udg.reset(n);
        for(auto&e:edges)udg.addEdge(e[0],e[1],e[2]);
        int ans=-1,ansnum=INT_MAX;
        REP(i,n){
            int dist[n];
            dijkstra(i,dist,udg);
            int cnt=accumulate(dist,dist+n,0,[&](int x,int y){return x+(y<=distanceThreshold);});
            if(ansnum>=cnt){
                ansnum=cnt;
                ans=i;
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
    vvi edges=makevvi("[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]");
    int distanceThreshold=4;
    auto ans=sol.findTheCity(n,edges,distanceThreshold);
    DBG(ans);

    system("pause");
    return 0;
}
