#include "utils.h"

class Solution {
public:
    int numPermsDISequence(string S) {
        int n=S.size();
        ll dp[n+1][n+2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        FOR(i,1,n+1){
            if(S[i-1]=='D'){
                REPR(j,i){
                    dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
                }
            }
            else{
                FOR(j,1,i+1){
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
                }
            }
        }
        return accumulate(dp[n],dp[n+1],0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="DID";
    auto ans=sol.numPermsDISequence(S);
    DBG(ans);

    system("pause");
    return 0;
}
