#include "utils.h"

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int deg[n];
        memset(deg,0,sizeof(deg));
        for(auto&e:edges){
            deg[e[1]]++;
        }
        vi ans;
        REP(i,n)if(!deg[i])ans.pb(i);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vvi edges=makevvi("[[0,1],[0,2],[2,5],[3,4],[4,2]]");
    auto ans=sol.findSmallestSetOfVertices(n,edges);
    DBGV(ans);

    system("pause");
    return 0;
}
