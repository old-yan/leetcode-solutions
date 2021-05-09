#include "Union.h"
#include "utils.h"

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        Union u(n);
        int ans=0;
        for(auto&e:edges){
            if(e[0]==3&&!u.unite(e[1]-1,e[2]-1))ans++;
        }
        Union u2(u);
        for(auto&e:edges){
            if(e[0]==1&&!u.unite(e[1]-1,e[2]-1))ans++;
            if(e[0]==2&&!u2.unite(e[1]-1,e[2]-1))ans++;
        }
        if(u.group==1&&u2.group==1)return ans;
        else return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    vvi edges=makevvi("[[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]");
    auto ans=sol.maxNumEdgesToRemove(n,edges);
    DBG(ans);

    system("pause");
    return 0;
}
