#include "utils.h"

class Solution {
    vi adj[200];
    int dist[200];
    void dijkstra(){
        memset(dist,0x3f,sizeof(dist));
        queue<int>Q;
        dist[0]=dist[1]=0;
        Q.push(0);
        Q.push(1);
        while(Q.size()){
            int cur=Q.front();
            Q.pop();
            for(auto a:adj[cur]){
                if(chmin(dist[a],dist[cur]+1)){
                    Q.push(a);
                }
            }
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for(auto&e:red_edges){
            adj[e[0]*2+1].pb(e[1]*2);
        }
        for(auto&e:blue_edges){
            adj[e[0]*2].pb(e[1]*2+1);
        }
        dijkstra();
        vi ans(n);
        REP(i,n){
            ans[i]=min(dist[i*2],dist[i*2+1]);
            if(ans[i]==0x3f3f3f3f)ans[i]=-1;
        }
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
