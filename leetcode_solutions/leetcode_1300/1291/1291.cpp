#include "utils.h"

const ll units[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
class Solution {
    int low,high;
    vi ans;
    void dfs(int curidx,int last,ll cur){
        if(cur/units[curidx+1]<low/units[curidx+1])return;
        if(cur/units[curidx+1]>high/units[curidx+1])return;
        if(curidx<0)ans.pb(cur);
        else if(last<9){
            dfs(curidx-1,last+1,cur+(last+1)*units[curidx]);
        }
    }
public:
    vector<int> sequentialDigits(int _low, int _high) {
        low=_low,high=_high;
        FOR(i,log10(low),log10(high)+1){
            REP(last,9)dfs(i-1,last,0);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int low=1000;
    int high=13000;
    auto ans=sol.sequentialDigits(low,high);
    DBGV(ans);

    system("pause");
    return 0;
}
