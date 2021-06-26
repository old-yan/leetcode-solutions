#include "Graph.h"
#include "utils.h"

class Solution {
    void init(vvi&edges){
        for(auto&e:edges)e[0]--,e[1]--;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        init(edges);
        int n=edges.size();
        dg.reset(n);
        for(auto&e:edges){
            dg.addEdge(e[0],e[1]);
        }
        if(count(dg.indeg,dg.indeg+n,0)){//能找到度数为2的特殊点
            vvi opt;
            for(auto&e:edges){
                if(dg.indeg[e[1]]==2){
                    opt.pb(e);
                }
            }
            tp.solve(dg);
            if(tp.visited[opt[0][0]])return {opt[1][0]+1,opt[1][1]+1};
            else return {opt[0][0]+1,opt[0][1]+1};
        }
        else{//从开头就在环上，找不到度数为2的特殊点
            tj.solve(dg);
            REPR(i,n-1){
                if(tj.color[edges[i][0]]==tj.color[edges[i][1]]){
                    return {edges[i][0]+1,edges[i][1]+1};
                }
            }
            return {};
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges{
        {1,2},{2,3},{3,4},{4,1},{1,5}
    };
    auto ans=sol.findRedundantDirectedConnection(edges);
    DBGV(ans);

    system("pause");
    return 0;
}
