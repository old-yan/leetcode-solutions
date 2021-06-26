#include "Graph.h"
#include "utils.h"

UndirectedGraph<>udg;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        udg.reset(n);
        for(auto&e:edges)udg.addEdge(--e[0],--e[1],e[2]);
        ll dist[n];
        dijkstra(n-1,dist,udg);

        vi seq(n);
        iota(ALL(seq),0);
        sort(ALL(seq),[&](int x,int y){return dist[x]<dist[y];});
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[n-1]=1;
        for(int a:seq){
            if(dist[a]>=dist[0])break;
            for(int _=udg.fi[a];~_;_=udg.ne[_]){
                int j=udg.to[_];
                if(dist[j]>dist[a])
                    dp[j]=(dp[j]+dp[a])%MOD;
            }
        }
        return dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vvi edges=makevvi("[[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]");
    auto ans=sol.countRestrictedPaths(n,edges);
    DBG(ans);

    system("pause");
    return 0;
}
