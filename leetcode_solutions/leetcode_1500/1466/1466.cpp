#include "utils.h"

class Solution {
    vector<pair<int,int>> adj[50000];
    int ans=0;
    void traverse(int cur,int parent){
        for(auto [a,dis]:adj[cur])if(a!=parent){
            ans+=dis;
            traverse(a,cur);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto&co:connections){
            int i=co[0],j=co[1];
            adj[i].emplace_back(j,1);
            adj[j].emplace_back(i,0);
        }
        traverse(0,-1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vvi connections=makevvi("[[0,1],[1,3],[2,3],[4,0],[4,5]]");
    auto ans=sol.minReorder(n,connections);
    DBG(ans);

    system("pause");
    return 0;
}
