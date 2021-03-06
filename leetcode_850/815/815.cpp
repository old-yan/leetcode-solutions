#include "utils.h"

class Solution {
    unordered_map<int,vi>M;
    unordered_set<int>S;
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        REP(i,routes.size()){
            for(int a:routes[i])M[a].pb(i);
        }
        queue<int>Q({source});
        S.insert(source);
        while(int l=Q.size()){
            while(l--){
                auto p=Q.front();
                Q.pop();
                for(int i:M[p]){
                    if(visited[i])
                    for(int a:routes[i])
                }
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi routes=makevvi("[[1,2,7],[3,6,7]]");
    int source=1;
    int target=6;
    auto ans=sol.numBusesToDestination(routes,source,target);
    DBG(ans);

    system("pause");
    return 0;
}
