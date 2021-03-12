#include "SegTree.h"
#include "utils.h"

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(!K)return 1;
        if(N>=K+W)return 1;
        double dp[K+W];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        double sum=1;
        FOR(cur,1,K+W){
            dp[cur]=sum/W;
            if(cur<K)sum+=dp[cur];
            if(cur-W>=0)sum-=dp[cur-W];
        }
        return accumulate(dp+K,dp+N+1,double(0))/accumulate(dp+K,dp+K+W,double(0));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=10;
    int K=1;
    int W=10;
    auto ans=sol.new21Game(N,K,W);
    DBG(ans);

    system("pause");
    return 0;
}
