#include "utils.h"

class Solution {
    vi adj[101];
    double dp[101]={0};
    void traverse(int cur,int parent,int resttime){
        if(!resttime)return;
        if(parent){
            for(int a:adj[cur])if(a!=parent){
                dp[a]=dp[cur]/(adj[cur].size()-1);
                traverse(a,cur,resttime-1);
            }
            if(resttime&&adj[cur].size()>1)dp[cur]=0;
        }
        else{
            for(int a:adj[cur]){
                dp[a]=dp[cur]/adj[cur].size();
                traverse(a,cur,resttime-1);
            }
            if(resttime&&adj[cur].size())dp[cur]=0;
        }
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        for(auto&e:edges){
            int i=e[0],j=e[1];
            adj[i].pb(j);
            adj[j].pb(i);
        }
        dp[1]=1;
        traverse(1,0,t);
        return dp[target];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    vvi edges=makevvi("[[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]]");
    int t=2;
    int target=4;
    auto ans=sol.frogPosition(n,edges,t,target);
    DBG(ans);

    system("pause");
    return 0;
}
