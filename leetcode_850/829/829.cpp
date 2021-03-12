#include "utils.h"

class Solution {
    int N,ans=0;
    vi factors;
    vi next;
    void dfs(int cur,ll curprod){
        if(cur==next.size()){
            int n=N/curprod;
            if(n%2&&curprod-n/2>0)ans++;
            if(curprod%2&&curprod/2>=n)ans++;
        }
        else{
            dfs(next[cur],curprod);
            REP(i,next[cur]-cur){
                curprod*=factors[cur];
                dfs(next[cur],curprod);
            }
        }
    }
public:
    int consecutiveNumbersSum(int _N) {
        N=_N;
        factors=getFactor(N,40000);
        next=next_different(factors);
        dfs(0,1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=1000;
    auto ans=sol.consecutiveNumbersSum(N);
    DBG(ans);

    system("pause");
    return 0;
}
