#include "Graph.h"
#include "utils.h"

UndirectedGraph<>udg;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        udg.reset(m*n);
        REP(i,m)REP(j,n)REP(k,2){
            int ii=i+di[k],jj=j+dj[k];
            if(VALID)udg.addEdge(i*n+j,ii*n+jj);
        }
        vi sources;
        REP(i,m)REP(j,n)if(isWater[i][j])sources.emplace_back(i*n+j);
        int dist[m*n];
        BFS(sources,dist,udg);
        vvi ans(m,vi(n));
        REP(i,m)REP(j,n)ans[i][j]=dist[i*n+j];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi isWater=makevvi("[[0,1],[0,0]]");
    auto ans=sol.highestPeak(isWater);
    DBGVV(ans);

    system("pause");
    return 0;
}
