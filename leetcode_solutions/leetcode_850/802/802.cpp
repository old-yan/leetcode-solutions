#include "utils.h"

class Solution {
    vi from[10000];
    int deg[10000]={0};
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int>Q;
        REP(i,n){
            for(int a:graph[i]){
                from[a].pb(i);
            }
            deg[i]=graph[i].size();
            if(!deg[i])Q.push(i);
        }
        vi ans;
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            ans.pb(p);
            for(int a:from[p]){
                if(!--deg[a]){
                    Q.push(a);
                }
            }
        }
        sort(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi graph=makevvi("[[1,2],[2,3],[5],[0],[5],[],[]]");
    auto ans=sol.eventualSafeNodes(graph);
    DBGV(ans);

    system("pause");
    return 0;
}
