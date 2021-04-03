#include "utils.h"

const int units[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
class Solution {
    vi ans;
    int k;
    void dfs(int i,int idx,int cur){
        cur+=i*units[idx];
        if(!idx)ans.pb(cur);
        else{
            if(i+k<10)dfs(i+k,idx-1,cur);
            if(k&&i-k>=0)dfs(i-k,idx-1,cur);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int _k) {
        k=_k;
        FOR(i,1,10){
            dfs(i,n-1,0);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    int k=7;
    auto ans=sol.numsSameConsecDiff(n,k);
    DBGV(ans);

    system("pause");
    return 0;
}
