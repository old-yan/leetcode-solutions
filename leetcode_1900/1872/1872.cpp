#include "utils.h"

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        ll _presum[n+1];
        _presum[0]=0;
        partial_sum(ALL(stones),_presum+1);
        auto presum=_presum+1;
        ll j=presum[n-1];
        ll dp[n+1];
        memset(dp,0x80,sizeof(dp));
        dp[n]=0;
        ll k=presum[n-1]-dp[n];
        REPR(i,n-1){
            dp[i]=k;
            chmax(k,presum[i-1]-dp[i]);
        }
        return dp[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{-1,2,-3,4,-5};
    auto ans=sol.stoneGameVIII(stones);
    DBG(ans);

    system("pause");
    return 0;
}
