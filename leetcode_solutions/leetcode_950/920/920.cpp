#include "utils.h"

class Solution {
    ll dp[100][101]={0};//dp[i][j]表示下标i及之前，承包j个音乐的类别数
public:
    int numMusicPlaylists(int N, int L, int K) {
        REP(i,K+1){
            dp[i][i+1]=1;
        }
        FOR(i,K+1,L){
            FOR(j,1,N+1){
                dp[i][j]=(dp[i-1][j]*(j-K)+dp[i-1][j-1])%MOD;
            }
        }
        ll ans=dp[L-1][N];
        REP(i,N)ans=ans*(i+1)%MOD;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=3;
    int L=3;
    int K=0;
    auto ans=sol.numMusicPlaylists(N,L,K);
    DBG(ans);

    system("pause");
    return 0;
}
