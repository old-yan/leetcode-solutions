#include "Graph.h"
#include "utils.h"

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        dg.reset(n);
        for(auto&p:prerequisites){
            dg.addEdge(p[0],p[1]);
        }
        int dist[n][n];
        REP(i,n)BFS(i,dist[i],dg);
        vector<bool>ans;
        for(auto&q:queries){
            ans.pb(dist[q[0]][q[1]]<0x3f3f3f3f);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    vvi prerequisites=makevvi("[[1,0]]");
    vvi queries=makevvi("[[0,1],[1,0]]");
    auto ans=sol.checkIfPrerequisite(n,prerequisites,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
