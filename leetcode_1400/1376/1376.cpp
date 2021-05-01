#include "utils.h"

class Solution {
    vi adj[100000];
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        REP(i,n)if(manager[i]>=0){
            adj[manager[i]].pb(i);
        }
        int ans=0;
        int dist[n];
        memset(dist,0x3f,sizeof(dist));
        queue<pair<int,int>>Q;
        dist[headID]=0;
        Q.emplace(headID,0);
        while(Q.size()){
            auto [cur,curdis]=Q.front();
            Q.pop();
            chmax(ans,curdis);
            for(int a:adj[cur]){
                Q.emplace(a,dist[a]=curdis+informTime[cur]);
            }
        }
        return ans;
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
