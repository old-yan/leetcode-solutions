#include "utils.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        REPR(i,n1-1){
            REPR(j,n2-1){
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                if(word1[i]==word2[j])chmax(dp[i][j],dp[i+1][j+1]+1);
            }
        }
        return word1.size()+word2.size()-dp[0][0]*2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="sea";
    string word2="eat";
    auto ans=sol.minDistance(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
