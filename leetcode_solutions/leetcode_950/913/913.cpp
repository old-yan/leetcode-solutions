#include "utils.h"

class Solution {
    #define X 200
    vi cat_go[X];
    vi mouse_go[X];
    int dp[2][X][X]={0};
    int fail[2][X][X]={0};
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();
        REP(i,n){
            for(int a:graph[i]){
                if(a)cat_go[i].pb(a);
                mouse_go[i].pb(a);
            }
        }
        queue<tuple<int,int,int>>Q;
        REP(i,2){
            FOR(j,1,n){
                dp[i][j][j]=2;
                Q.emplace(i,j,j);
                dp[i][j][0]=1;
                Q.emplace(i,j,0);
            }
        }
        while(Q.size()){
            auto [cur,cat,mouse]=Q.front();
            Q.pop();
            if(cur){
                if(dp[cur][cat][mouse]==1){
                    for(int a:mouse_go[mouse]){
                        if(!dp[0][cat][a]){
                            dp[0][cat][a]=1;
                            Q.emplace(0,cat,a);
                        }
                    }
                }
                else{
                    for(int a:mouse_go[mouse]){
                        if(!dp[0][cat][a]&&++fail[0][cat][a]==mouse_go[a].size()){
                            dp[0][cat][a]=2;
                            Q.emplace(0,cat,a);
                        }
                    }
                }
            }
            else{
                if(dp[cur][cat][mouse]==2){
                    for(int a:cat_go[cat]){
                        if(!dp[1][a][mouse]){
                            dp[1][a][mouse]=2;
                            Q.emplace(1,a,mouse);
                        }
                    }
                }
                else{
                    for(int a:cat_go[cat]){
                        if(!a)continue;
                        if(!dp[1][a][mouse]&&++fail[1][a][mouse]==cat_go[a].size()){
                            dp[1][a][mouse]=1;
                            Q.emplace(1,a,mouse);
                        }
                    }
                }
            }
        }
        return dp[0][2][1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi graph=makevvi("[[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]");
    auto ans=sol.catMouseGame(graph);
    DBG(ans);

    system("pause");
    return 0;
}
