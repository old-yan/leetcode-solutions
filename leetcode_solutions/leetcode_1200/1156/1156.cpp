#include "utils.h"

class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.size();
        int cnt[26]={0};
        for(char c:text)cnt[c-'a']++;
        int dp[n+1][26][2];
        memset(dp,0,sizeof(dp));
        int ans=0;
        FOR(i,1,n+1){
            char c=text[i-1]-'a';
            REP(j,26)if(cnt[j]){
                if(c==j)dp[i][j][0]=dp[i-1][j][0]+1;
                if(c!=j&&cnt[c]>dp[i-1][j][0])chmax(dp[i][j][1],dp[i-1][j][0]+1);
                if(c==j)chmax(dp[i][j][1],dp[i-1][j][1]+1);
                chmax(ans,dp[i][j][0]);
                chmax(ans,dp[i][j][1]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string text="aaabaaa";
    auto ans=sol.maxRepOpt1(text);
    DBG(ans);

    system("pause");
    return 0;
}
