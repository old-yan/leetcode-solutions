#include "utils.h"

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        int sum[n][n];
        REP(i,n){
            int cnt=0;
            FOR(j,i,n){
                cnt+=stones[j];
                sum[i][j]=cnt;
            }
        }
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        REP(i,n){
            REP(j,n-i){
                dp[j][j+i]=i?max(sum[j+1][j+i]-dp[j+1][j+i],sum[j][j+i-1]-dp[j][j+i-1]):0;
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{5,3,1,4,2};
    auto ans=sol.stoneGameVII(stones);
    DBG(ans);

    system("pause");
    return 0;
}
