#include "Graph.h"
#include "utils.h"

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        dg.reset(n);
        REP(i,n)if(manager[i]>=0){
            dg.addEdge(manager[i],i,informTime[manager[i]]);
        }
        int dist[n];
        BFS(headID,dist,dg);
        return *max_element(dist,dist+n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=1;
    int headID=0;
    vi manager{-1};
    vi informTime{0};
    auto ans=sol.numOfMinutes(n,headID,manager,informTime);
    DBG(ans);

    system("pause");
    return 0;
}
