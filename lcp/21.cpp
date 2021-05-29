#include "Graph.h"
#include "utils.h"

UndirectedGraph udg;
class Solution {
    void init(vvi&edges,int&startA,int&startB){
        for(auto&e:edges)e[0]--,e[1]--;
        startA--;
        startB--;
    }
public:
    int chaseGame(vector<vector<int>>& edges, int startA, int startB) {
        init(edges,startA,startB);
        int n=edges.size();
        udg.reset(n);
        for(auto&e:edges){
            udg.addEdge(e[0],e[1]);
            if((e[0]==startA&&e[1]==startB)||(e[0]==startB&&e[1]==startA))return 1;
        }
        utj.solve(udg);
        vector<bool>onloop(n,false);
        REP(i,n)if(!utj.isBridge(edges[i][0],edges[i][1])){
            onloop[edges[i][0]]=onloop[edges[i][1]]=true;
        }
        int loopsize=count(ALL(onloop),true);

        int distA[n],distB[n];
        BFS(startA,distA,udg);
        BFS(startB,distB,udg);
        if(loopsize>=4){
            REP(i,n)if(onloop[i]&&distB[i]+1<distA[i]){
                return -1;
            }
        }
        int ans=0;
        REP(i,n){
            if(distB[i]+1<distA[i]){
                chmax(ans,distA[i]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges=makevvi("[[1,2],[2,3],[3,4],[4,1],[2,5],[5,6]]");
    int startA=3;
    int startB=5;
    auto ans=sol.chaseGame(edges,startA,startB);
    DBG(ans);

    system("pause");
    return 0;
}
