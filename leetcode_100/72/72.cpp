#include "utils.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size()+1][word2.size()+1];
        REPR(i,word1.size()){
            REPR(j,word2.size()){
                if(i==word1.size())dp[i][j]=word2.size()-j;
                else if(j==word2.size())dp[i][j]=word1.size()-i;
                else{
                    dp[i][j]=dp[i+1][j+1];
                    if(word1[i]!=word2[j])dp[i][j]+=1;
                    chmin(dp[i][j],min(dp[i+1][j],dp[i][j+1])+1);
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="horse";
    string word2="ros";
    auto ans=sol.minDistance(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
