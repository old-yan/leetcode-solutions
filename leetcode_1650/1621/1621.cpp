#include "utils.h"

class Solution {
public:
    int numberOfSets(int n, int k) {
        ll dp[1001]={0};
        dp[1]=1;
        for(int i=1;i<=k;i++){
            partial_sum(dp+1,dp+n+1,dp+1,[](ll x,ll y){return (x+y)%MOD;});
            partial_sum(dp+1,dp+n+1,dp+1,[](ll x,ll y){return (x+y)%MOD;});
            memmove(dp+1,dp,(n+1)*sizeof(int));
        }
        return accumulate(dp+1,dp+n+1,0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    int k=2;
    auto ans=sol.numberOfSets(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
