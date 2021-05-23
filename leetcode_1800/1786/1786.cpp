#include "utils.h"

class Solution {
    vector<pair<int,int>>adj[20000];
    ll n,dis[20000],deg[20000]={0},dp[20000]={0};
    void dijkstra(vvi&edges){
        for(auto&e:edges){
            int i=e[0]-1,j=e[1]-1;
            adj[i].emplace_back(j,e[2]);
            adj[j].emplace_back(i,e[2]);
        }
        memset(dis,0x3f,sizeof(dis));
        dis[n-1]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>Q;
        Q.emplace(0,n-1);
        while(Q.size()){
            auto [curd,cur]=Q.top();
            Q.pop();
            if(curd!=dis[cur])continue;
            for(auto [a,d]:adj[cur]){
                if(chmin(dis[a],curd+d)){
                    Q.emplace(dis[a],a);
                }
            }
        }
    }
    void topo(vvi&edges){
        for(auto&e:edges){
            int i=e[0]-1,j=e[1]-1;
            if(dis[i]>dis[j])deg[j]++;
            if(dis[j]>dis[i])deg[i]++;
        }
        queue<int>Q;
        dp[0]=1;
        REP(i,n)if(!deg[i])Q.push(i);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            for(auto [a,_]:adj[p])if(dis[p]>dis[a]){
                dp[a]=(dp[a]+dp[p])%MOD;
                if(!--deg[a]){
                    Q.push(a);
                }
            }
        }
    }
public:
    int countRestrictedPaths(int _n, vector<vector<int>>& edges) {
        n=_n;
        dijkstra(edges);
        topo(edges);
        return dp[n-1];
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
