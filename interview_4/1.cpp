#include "Graph.h"
#include "utils.h"

DirectedGraph<int>dg;
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        dg.reset(n);
        for(auto&g:graph){
            dg.addEdge(g[0],g[1]);
        }
        int dist[n];
        BFS(start,dist,dg);
        return dist[target]<0x3f3f3f3f;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi graph=makevvi("[[0, 1], [0, 2], [1, 2], [1, 2]]");
    int start=0;
    int target=2;
    auto ans=sol.findWhetherExistsPath(n,graph,start,target);
    DBG(ans);

    system("pause");
    return 0;
}
