#include "utils.h"

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        int mat[n][n],adj[n];
        memset(adj,0,sizeof(adj));
        memset(mat,0x3f,sizeof(mat));
        for(auto&e:edges){
            int i=e[0]-1,j=e[1]-1;
            mat[i][j]=mat[j][i]=1;
            adj[i]|=1<<j;
            adj[j]|=1<<i;
        }
        REP(k,n)REP(i,n)REP(j,n)chmin(mat[i][j],mat[i][k]+mat[k][j]);
        vi ans(n-1);
        bool visited[1<<n];
        memset(visited,0,sizeof(visited));
        queue<pair<int,int>>Q;
        REP(i,n){
            visited[1<<i]=true;
            Q.emplace(1<<i,0);
        }
        while(Q.size()){
            auto [p,curdis]=Q.front();
            Q.pop();
            REP(i,n)if(!(p>>i&1)&&(p&adj[i])&&!visited[p|(1<<i)]){
                visited[p|(1<<i)]=true;
                int dis=curdis;
                REP(j,n)if(p>>j&1)chmax(dis,mat[i][j]);
                ans[dis-1]++;
                Q.emplace(p|(1<<i),dis);
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
    vvi edges=makevvi("[[1,2],[2,3],[2,4]]");
    auto ans=sol.countSubgraphsForEachDiameter(n,edges);
    DBGV(ans);

    system("pause");
    return 0;
}
