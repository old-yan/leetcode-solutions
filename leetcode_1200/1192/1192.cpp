#include "Tarjan.h"
#include "utils.h"

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        bool isb[connections.size()];
        fill(isb,isb+connections.size(),false);
        tarjanBridge tc(ALL(connections),isb);
        tc.findBridge();
        vvi ans;
        REP(i,connections.size()){
            if(isb[i]){
                ans.emplace_back(connections[i]);
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
