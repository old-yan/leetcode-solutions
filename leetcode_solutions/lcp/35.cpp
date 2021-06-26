#include "Graph.h"
#include "utils.h"

DirectedGraph<int>dg;
class Solution {
public:
    int electricCarPlan(vector<vector<int>>& paths, int cnt, int start, int end, vector<int>& charge) {
        int n=charge.size();
        auto getid=[&](int i,int j){return i*(cnt+1)+j;};
        dg.reset(n*(cnt+1));
        for(auto&p:paths){
            int a=p[0],b=p[1],w=p[2];
            FOR(i,w,cnt+1){
                dg.addEdge(getid(a,i),getid(b,i-w),w);
                dg.addEdge(getid(b,i),getid(a,i-w),w);
            }
        }
        REP(i,n){
            REP(j,cnt){
                dg.addEdge(getid(i,j),getid(i,j+1),charge[i]);
            }
        }
        int dist[n*(cnt+1)];
        dijkstra(getid(start,0),dist,dg);
        return dist[getid(end,0)];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi paths=makevvi("[[0,4,2],[4,3,5],[3,0,5],[0,1,5],[3,2,4],[1,2,8]]");
    int cnt=8;
    int start=0;
    int end=2;
    vi charge{4,1,1,3,2};
    auto ans=sol.electricCarPlan(paths,cnt,start,end,charge);
    DBG(ans);

    system("pause");
    return 0;
}
