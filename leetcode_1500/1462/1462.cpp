#include "utils.h"

class Solution {
    vi adj[100];
    bitset<100>isChildren[100];
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for(auto&pre:prerequisites){
            adj[pre[0]].pb(pre[1]);
        }
        REP(i,n){
            auto&visited=isChildren[i];
            static queue<int>Q;
            visited.set(i);
            Q.push(i);
            while(Q.size()){
                auto p=Q.front();
                Q.pop();
                for(int a:adj[p]){
                    if(!visited[a]){
                        visited.set(a);
                        Q.push(a);
                    }
                }
            }
        }
        vector<bool>ans;
        for(auto&q:queries){
            ans.pb(isChildren[q[0]][q[1]]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    vvi prerequisites=makevvi("[[1,0]]");
    vvi queries=makevvi("[[0,1],[1,0]]");
    auto ans=sol.checkIfPrerequisite(n,prerequisites,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
