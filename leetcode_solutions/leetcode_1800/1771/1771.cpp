#include "utils.h"

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string word=word1+word2;
        int n=word.size();
        int dp[n][n],ans=0;
        memset(dp,0,sizeof(dp));
        REP(i,n){
            REP(j,n-i){
                if(!i)dp[j][j+i]=1;
                else{
                    if(word[j]==word[j+i]){
                        dp[j][j+i]=2+dp[j+1][j+i-1];
                        if(j<word1.size()&&j+i>=word1.size()){
                            chmax(ans,dp[j][j+i]);
                        }
                    }
                    else dp[j][j+i]=max(dp[j][j+i-1],dp[j+1][j+i]);
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

    string word1="cacb";
    string word2="cbba";
    auto ans=sol.longestPalindrome(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
