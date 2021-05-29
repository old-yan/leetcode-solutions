#include "Graph.h"
#include "utils.h"

class Solution {
    void init(vvi&times){
        for(auto&t:times)t[0]--,t[1]--;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        init(times);
        dg.reset(n);
        for(auto&t:times){
            dg.addEdge(t[0],t[1],t[2]);
        }
        int dist[n];
        dijkstra(k-1,dist,dg);
        auto Max=*max_element(dist,dist+n);
        return Max==0x3f3f3f3f?-1:Max;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi times=makevvi("[[1,2,1]]");
    int n=2;
    int k=2;
    auto ans=sol.networkDelayTime(times,n,k);
    DBG(ans);

    system("pause");
    return 0;
}
