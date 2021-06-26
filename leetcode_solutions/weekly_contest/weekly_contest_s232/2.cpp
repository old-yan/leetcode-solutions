#include "utils.h"

class Solution {
public:
    //找出度最大的结点，就是中心结点
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vi deg(n+1,0);
        for(auto&e:edges){
            deg[e[0]]++;
            deg[e[1]]++;
        }
        return max_element(ALL(deg))-deg.begin();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges=makevvi("[[1,2],[2,3],[4,2]]");
    auto ans=sol.findCenter(edges);
    DBGVV(ans);

    system("pause");
    return 0;
}
