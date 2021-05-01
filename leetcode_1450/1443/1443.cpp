#include "utils.h"

class Solution {
    vi adj[100000];
    pair<bool,int> traverse(int cur,int parent, vector<bool>& hasApple){
        auto ans=make_pair(hasApple[cur],0);
        for(auto a:adj[cur])if(a!=parent){
            auto res=traverse(a,cur,hasApple);
            if(res.first){
                ans.first=true;
                ans.second+=res.second+2;
            }
        }
        return ans;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto&e:edges){
            int i=e[0],j=e[1];
            adj[i].pb(j);
            adj[j].pb(i);
        }
        return traverse(0,-1,hasApple).second;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    vvi edges=makevvi("[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]");
    vector<bool>hasApple{false,false,true,false,true,true,false};
    auto ans=sol.minTime(n,edges,hasApple);
    DBG(ans);

    system("pause");
    return 0;
}
