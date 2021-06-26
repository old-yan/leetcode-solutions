#include "utils.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Union u(edges.size());
        for(auto&edge:edges){
            if(!u.unite(edge[0]-1,edge[1]-1)){
                return edge;
            }
        }
        return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges{
        {1,2}, {2,3}, {3,4}, {1,4}, {1,5}
    };
    auto ans=sol.findRedundantConnection(edges);
    DBGV(ans);

    system("pause");
    return 0;
}
