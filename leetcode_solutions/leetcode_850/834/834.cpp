#include "utils.h"

class Solution {
    int N;
    vi adj[10000];
    int parent[10000];
    int dis_down[10000];
    int num_down[10000];
    void findParent(int cur,int p){
        parent[cur]=p;
        num_down[cur]=1;
        dis_down[cur]=0;
        for(int i=0;i<adj[cur].size();){
            if(adj[cur][i]!=p){
                findParent(adj[cur][i],cur);
                num_down[cur]+=num_down[adj[cur][i]];
                dis_down[cur]+=dis_down[adj[cur][i]]+num_down[adj[cur][i]];
                i++;
            }
            else adj[cur].erase(adj[cur].begin()+i);
        }
    }
    void traverse(int cur,vi&ans){
        if(!cur)ans[cur]=dis_down[cur];
        else{
            ans[cur]=ans[parent[cur]]-num_down[cur]*2+N;
        }
        for(int child:adj[cur])traverse(child,ans);
    }
public:
    vector<int> sumOfDistancesInTree(int _N, vector<vector<int>>& edges) {
        N=_N;
        for(auto&edge:edges){
            int i=edge[0],j=edge[1];
            adj[i].pb(j);
            adj[j].pb(i);
        }
        findParent(0,-1);
        vi ans(N);
        traverse(0,ans);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=6;
    vvi edges=makevvi("[[0,1],[0,2],[2,3],[2,4],[2,5]]");
    auto ans=sol.sumOfDistancesInTree(N,edges);
    DBGV(ans);

    system("pause");
    return 0;
}
