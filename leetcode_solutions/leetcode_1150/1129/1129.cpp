#include "Graph.h"
#include "utils.h"

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        dg.reset(n*2);
        for(auto&e:red_edges){
            dg.addEdge(e[0]<<1,e[1]<<1^1);
        }
        for(auto&e:blue_edges){
            dg.addEdge(e[0]<<1^1,e[1]<<1);
        }
        vi ans(n,0x3f3f3f3f);
        int dist0[n*2],dist1[n*2];
        BFS(0,dist0,dg);
        BFS(1,dist1,dg);
        REP(i,n){
            chmin(ans[i],min(min(dist0[i*2],dist0[i*2+1]),min(dist1[i*2],dist1[i*2+1])));
        }
        for(int&a:ans)a=a==0x3f3f3f3f?-1:a;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi red_edges=makevvi("[[0,1],[1,2]]");
    vvi blue_edges=makevvi("[]");
    auto ans=sol.shortestAlternatingPaths(n,red_edges,blue_edges);
    DBGV(ans);

    system("pause");
    return 0;
}
