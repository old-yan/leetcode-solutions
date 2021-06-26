#include "Union.h"
#include "utils.h"

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        Union u(n+1);
        FOR(i,threshold+1,n){
            for(int j=i*2;j<=n;j+=i){
                u.unite(i,j);
            }
        }
        vector<bool> ans(queries.size());
        REP(i,queries.size()){
            ans[i]=u.same(queries[i][0],queries[i][1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    int threshold=2;
    vvi queries=makevvi("[[1,4],[2,5],[3,6]]");
    auto ans=sol.areConnected(n,threshold,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
