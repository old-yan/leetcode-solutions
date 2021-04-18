#include "utils.h"

class Solution {
    vi adj[10000];
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        for(auto&p:paths){
            adj[p[0]-1].pb(p[1]-1);
        }
        vi ans(n,0x0f);
        REP(i,n){
            if(__builtin_popcount(ans[i])>1){
                for(int a:adj[i]){
                    if(__builtin_popcount(ans[a])==1]){
                        ans[i]&=0x0f-ans[a];
                    }
                }
                if(__builtin_popcount(ans[i])>1)ans[i]&=-ans[i];
                for(int a:adj[i]){
                    ans[a]&=0x0f-ans[i];
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    vvi paths=makevvi("[[1,2],[2,3],[3,1]]");
    auto ans=sol.gardenNoAdj(n,paths);
    DBGV(ans);

    system("pause");
    return 0;
}
