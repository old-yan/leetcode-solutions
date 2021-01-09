#include "utils.h"

class Solution {
    int n;
    vi ans;
    void dfs(int i){
        if(i<=n){
            ans.pb(i);
            REP(j,10){
                dfs(i*10+j);
            }
        }
    }
public:
    vector<int> lexicalOrder(int _n) {
        n=_n;
        FOR(i,1,10){
            dfs(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=50;
    auto ans=sol.lexicalOrder(n);
    DBGV(ans);

    system("pause");
    return 0;
}
