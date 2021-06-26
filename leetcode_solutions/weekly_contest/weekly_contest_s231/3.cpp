#include "Heap.h"
#include "utils.h"

int mindis[20001];
int ways[20001];
int deg[20001];
class Solution {
    vector<pair<int,int>>adj[20001];
    void getMindis(int n){
        auto comp=[&](int x,int y){
            return mindis[x]>mindis[y];
        };
        BiHeap<int,0>H(comp);
        H.push(n);
        while(H.size()){
            int near=H.top();
            H.pop();
            int near_dis=mindis[near];
            for(auto [a,dis]:adj[near]){
                if(chmin(mindis[a],near_dis+dis)){
                    H.push(a);
                }
            }
        }
    }
    void getWays(int n){
        queue<int>Q;
        for(int i=1;i<=n;i++){
            for(auto [a,dis]:adj[i]){
                if(mindis[a]>mindis[i])deg[i]++;
            }
            if(!deg[i])Q.push(i);
        }
        ways[1]=1;
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            for(auto [a,dis]:adj[p]){
                if(mindis[a]<mindis[p]){
                    ways[a]=(ways[a]+ways[p])%MOD;
                    if(!--deg[a])Q.push(a);
                }
            }
        }
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        fill(mindis+1,mindis+n+1,INT_MAX);
        mindis[n]=0;
        memset(ways,0,sizeof(ways));
        memset(deg,0,sizeof(deg));
        for(auto&edge:edges){
            int i=edge[0],j=edge[1],dis=edge[2];
            adj[i].emplace_back(j,dis);
            adj[j].emplace_back(i,dis);
        }
        getMindis(n);
        getWays(n);
        return ways[n];
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
