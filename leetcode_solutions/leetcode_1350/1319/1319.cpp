#include "Union.h"
#include "utils.h"

Union u(100000);
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        u.reset();
        u.group=n;
        for(auto&A:connections)u.unite(A[0],A[1]);
        return u.group-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vvi connections=makevvi("[[0,1],[0,2],[3,4],[2,3]]");
    auto ans=sol.makeConnected(n,connections);
    DBG(ans);

    system("pause");
    return 0;
}
