#include "Heap.h"
#include "utils.h"

class Solution {
    vector<pair<int,int>>adj[100];
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto&e:edges){
            int i=e[0],j=e[1],k=e[2];
            adj[i].emplace_back(j,k);
            adj[j].emplace_back(i,k);
        }
        int ans=-1,ansnum=INT_MAX;
        REP(i,n){
            int dist[n];
            memset(dist,0x3f,sizeof(dist));
            auto comp=[&](int x,int y){return dist[x]>dist[y];};
            Heap<int>H(comp);
            dist[i]=0;
            H.push(i);
            int cnt=0;
            while(H.size()){
                auto cur=H.top();
                int dis=dist[cur];
                H.pop();
                if(dis>distanceThreshold)break;
                cnt++;
                for(auto [a,d]:adj[cur]){
                    if(chmin(dist[a],dis+d)){
                        H.push(a);
                    }
                }
            }
            if(cnt<=ansnum){
                ansnum=cnt;
                ans=i;
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
    vvi edges=makevvi("[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]");
    int distanceThreshold=4;
    auto ans=sol.findTheCity(n,edges,distanceThreshold);
    DBG(ans);

    system("pause");
    return 0;
}
