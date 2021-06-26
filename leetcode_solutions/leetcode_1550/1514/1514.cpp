#include "Graph.h"
#include "utils.h"

UndirectedGraph<double>udg;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        udg.reset(n);
        REP(i,edges.size()){
            udg.addEdge(edges[i][0],edges[i][1],-log(succProb[i]));
        }
        double dist[n];
        dijkstra(start,dist,udg);
        return exp(-dist[end]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi edges=makevvi("[[0,1],[1,2],[0,2]]");
    vector<double>succProb{0.5,0.5,0.2};
    int start=0;
    int end=2;
    auto ans=sol.maxProbability(n,edges,succProb,start,end);
    DBG(ans);

    system("pause");
    return 0;
}
