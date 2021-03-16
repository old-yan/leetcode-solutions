#include "utils.h"

class Solution {
    int dp[500][500];
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,0,sizeof(dp));
        REP(i,n){
            REP(j,n-i){
                dp[j][j+i]=max(piles[j]-dp[j+1][j+i],piles[j+i]-dp[j][j+i-1]);
            }
        }
        return dp[0][n-1]>0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi piles{5,3,4,5};
    auto ans=sol.stoneGame(piles);
    DBG(ans);

    system("pause");
    return 0;
}
