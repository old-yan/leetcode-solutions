#include "utils.h"

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        bool connect[n][n];
        int deg[n];
        memset(connect,0,sizeof(connect));
        memset(deg,0,sizeof(deg));
        for(auto&r:roads){
            connect[r[0]][r[1]]=connect[r[1]][r[0]]=true;
            deg[r[0]]++;
            deg[r[1]]++;
        }
        int ans=0;
        REP(i,n){
            REP(j,i){
                chmax(ans,deg[i]+deg[j]-connect[i][j]);
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
    vvi roads=makevvi("[[0,1],[0,3],[1,2],[1,3]]");
    auto ans=sol.maximalNetworkRank(n,roads);
    DBG(ans);

    system("pause");
    return 0;
}
