#include "Heap.h"
#include "utils.h"

class Solution {
    vector<pair<int,int>>adj[3000];
    int mindis[3000];
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        for(auto&edge:edges){
            int i=edge[0],j=edge[1],dis=edge[2]+1;
            adj[i].emplace_back(j,dis);
            adj[j].emplace_back(i,dis);
        }
        memset(mindis,0x3f,sizeof(mindis));
        mindis[0]=0;
        Heap H([&](int x,int y){
            return mindis[x]>mindis[y];
        });
        H.push(0);
        while(H.size()){
            auto cur=H.top();
            H.pop();
            for(auto [a,d]:adj[cur]){
                if(chmin(mindis[a],mindis[cur]+d)){
                    H.push(a);
                }
            }
        }
        int ans=0;
        for(auto&edge:edges){
            int i=edge[0],j=edge[1],mid=edge[2];
            int left=max(0,maxMoves-mindis[i]);
            int right=max(0,maxMoves-mindis[j]);
            ans+=min(mid,left+right);
        }
        REP(i,n){
            if(mindis[i]<=maxMoves)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges=makevvi("[[1,2,5],[0,3,3],[1,3,2],[2,3,4],[0,4,1]]");
    int maxMoves=7;
    int n=5;
    auto ans=sol.reachableNodes(edges,maxMoves,n);
    DBG(ans);

    system("pause");
    return 0;
}
