#include "Union.h"
#include "utils.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        Union u(n);
        REP(i,n){
            REP(j,int(graph[i].size())-1){
                u.unite(graph[i][j],graph[i][j+1]);
            }
            if(graph[i].size()&&u.same(i,graph[i][0]))return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi graph=makevvi("[[4,1],[0,2],[1,3],[2,4],[3,0]]");
    auto ans=sol.isBipartite(graph);
    DBG(ans);

    system("pause");
    return 0;
}
