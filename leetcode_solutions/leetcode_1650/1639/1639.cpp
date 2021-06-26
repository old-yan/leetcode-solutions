#include "utils.h"

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m=words.size(),n=words[0].size(),l=target.size();
        int have[n][26];
        memset(have,0,sizeof(have));
        REP(i,m)REP(j,n)have[j][words[i][j]-'a']++;
        int dp[n+1][l+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        REP(i,n){
            dp[i+1][0]=1;
            REP(j,l){
                dp[i+1][j+1]=(dp[i][j+1]+(ll)dp[i][j]*have[i][target[j]-'a'])%MOD;
            }
        }
        return dp[n][l];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"acca","bbbb","caca"};
    string target="aba";
    auto ans=sol.numWays(words,target);
    DBG(ans);

    system("pause");
    return 0;
}
