#include "Graph.h"
#include "utils.h"

UndirectedGraph udg;
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        udg.reset(n);
        for(auto&c:connections){
            udg.addEdge(c[0],c[1]);
        }
        utj.solve(udg);
        vvi ans;
        for(auto&c:connections){
            if(utj.isBridge(c[0],c[1])){
                ans.emplace_back(c);
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
    vvi connections=makevvi("[[0,1],[1,2],[2,0],[1,3]]");
    auto ans=sol.criticalConnections(n,connections);
    DBGVV(ans);

    system("pause");
    return 0;
}
