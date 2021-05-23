#include "utils.h"

class Solution {
    unordered_map<char,int>M;
    void init(){
        string s="aeiou";
        REP(i,5){
            M[s[i]]=i+1;
        }
    }
public:
    int longestBeautifulSubstring(string word) {
        init();
        int n=word.size();
        int dp[n+1][6];
        memset(dp,0x80,sizeof(dp));
        dp[0][0]=0;
        int ans=0;
        REP(i,n){
            dp[i+1][0]=0;
            int j=M[word[i]];
            chmax(dp[i+1][j],dp[i][j]+1);
            chmax(dp[i+1][j],dp[i][j-1]+1);
            chmax(ans,dp[i+1][5]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="aeiaaioaaaaeiiiiouuuooaauuaeiu";
    auto ans=sol.longestBeautifulSubstring(word);
    DBG(ans);

    system("pause");
    return 0;
}
