#include "utils.h"

class Solution {
public:
    int superEggDrop(int k, int n) {
        ll dp[k+1][n+1];
        memset(dp,0,sizeof(dp));
        int ans=INT_MAX;
        FOR(i,1,k+1){
            FOR(j,1,n+1){
                dp[i][j]=1+dp[i][j-1]+dp[i-1][j-1];
                if(dp[i][j]>=n){
                    chmin(ans,int(j));
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=1;
    int n=3;
    auto ans=sol.superEggDrop(k,n);
    DBG(ans);

    system("pause");
    return 0;
}
