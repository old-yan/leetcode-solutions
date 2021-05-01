#include "utils.h"

class Solution {
    vi can[27];
    void init(){
        REP(i,27){
            int a1=i/9,b1=i/3%3,c1=i%3;
            if(a1==b1||b1==c1)continue;
            REP(j,27){
                int a2=j/9,b2=j/3%3,c2=j%3;
                if(a2==b2||b2==c2)continue;
                if(a1==a2||b1==b2||c1==c2)continue;
                can[i].pb(j);
            }
        }
    }
public:
    int numOfWays(int n) {
        init();
        int dp[n][27];
        memset(dp,0,sizeof(dp));
        REP(j,27)if(can[j].size())dp[0][j]=1;
        FOR(i,1,n){
            REP(j,27){
                for(int a:can[j]){
                    dp[i][a]=(dp[i][a]+dp[i-1][j])%MOD;
                }
            }
        }
        return accumulate(dp[n-1],dp[n],0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=1;
    auto ans=sol.numOfWays(n);
    DBG(ans);

    system("pause");
    return 0;
}
