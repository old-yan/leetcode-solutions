#include "utils.h"
#include "Graph.h"

class Solution {
public:
    //经典问题，先计算单源最短距离，再从近到远进行动态规划
    int countPaths(int n, vector<vector<int>>& roads) {
        if(n==1)return 1;
        //本题数据结构为无向图
        static UndirectedGraph<ll>udg;
        //重置无向图
        udg.reset(n);
        //用一个矩阵存放相互距离
        ll mat[n][n];
        memset(mat,0x3f,sizeof(mat));
        for(auto&r:roads){
            int i=r[0],j=r[1],t=r[2];
            mat[i][j]=mat[j][i]=t;
            udg.addEdge(i,j,t);
        }
        //dijkstra计算最短路
        ll dis[n];
        dijkstra(0,dis,udg);
        //按照从近到远排列
        int seq[n];
        iota(seq,seq+n,0);
        sort(seq,seq+n,[&](int x,int y){return dis[x]<dis[y];});
        ll dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        //dp[i]可以由dp[j]转移而来，当且仅当j代表的点的最短距离加上从j到i的距离等于i代表的点的最短距离
        for(int i=1;;i++){
            for(int j=0;j<i;j++){
                if(dis[seq[j]]+mat[seq[j]][seq[i]]==dis[seq[i]]){
                    dp[i]+=dp[j];dp[i]%=MOD;
                }
            }
            if(seq[i]==n-1)return dp[i];
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    vvi roads=makevvi("[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]");
    auto ans=sol.countPaths(n,roads);
    DBG(ans);

    system("pause");
    return 0;
}
