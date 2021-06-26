#include "utils.h"

int __cuts[1002];
auto cuts=__cuts+1;
class Solution {
public:
    int minCost(int n, vector<int>& _cuts) {
        sort(ALL(_cuts));
        int m=_cuts.size();
        cuts[-1]=0;
        REP(i,m)cuts[i]=_cuts[i];
        cuts[m]=n;
        int dp[m+2][m+2];
        memset(dp,0,sizeof(dp));
        REP(i,m){
            FOR(j,1,m-i+1){
                dp[j][j+i]=0x3f3f3f3f;
                FOR(k,j,j+i+1){
                    chmin(dp[j][j+i],dp[j][k-1]+dp[k+1][j+i]);
                }
                dp[j][j+i]+=cuts[j+i]-cuts[j-2];
            }
        }
        return dp[1][m];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=7;
    vi cuts{1,3,4,5};
    auto ans=sol.minCost(n,cuts);
    DBG(ans);

    system("pause");
    return 0;
}
