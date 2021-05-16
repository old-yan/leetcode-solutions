#include "utils.h"

class Solution {
    vi adj[500];
    int parent[500];
    bool visited[500]={0};
public:
    int checkWays(vector<vector<int>>& pairs) {
        vi pts;
        for(auto&p:pairs){
            int i=p[0]-1,j=p[1]-1;
            adj[i].pb(j);
            if(adj[i].size()==1)pts.pb(i);
            adj[j].pb(i);
            if(adj[j].size()==1)pts.pb(j);
        }
        sort(ALL(pts),[&](int x,int y){return adj[x].size()>adj[y].size();});
        memset(parent,0xff,sizeof(parent));
        bool equal=false;
        if(adj[pts[0]].size()!=pts.size()-1)return 0;
        for(auto p:pts){
            for(int a:adj[p]){
                if(!visited[a]){
                    if(parent[a]!=parent[p])return 0;
                    if(adj[a].size()==adj[p].size())equal=true;
                    parent[a]=p;
                }
            }
            visited[p]=true;
        }
        return equal?2:1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi pairs=makevvi("[[1,2],[2,3]]");
    auto ans=sol.checkWays(pairs);
    DBG(ans);

    system("pause");
    return 0;
}
