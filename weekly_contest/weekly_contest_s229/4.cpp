#include "utils.h"

class Solution {
public:
    //本题可以理解为将word1和word2合并，然后在里面找最长回文子序列
    //最长回文子序列的求法参见第516题
    //但是需要注意的是，取出的最长回文子序列必须满足既有word1的成分，也有word2的成分
    //所以长度为1的回文子序列，不会更新ans；
    //长度大于1的回文子序列，需要头部在word1里，尾部在word2里
    int longestPalindrome(string word1, string word2) {
        string s=word1+word2;
        int n1=word1.size(),n2=word2.size(),n=n1+n2;
        //dp[i][j]表示s从下标i到下标j，内部能取到的最长回文子序列
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                //每个字符本身就是一个回文子序列，所以dp值至少为1
                dp[i][j]=1;
                if(s[i]==s[j]){
                    if(i==j)dp[i][j]=1;
                    else{
                        dp[i][j]=dp[i+1][j-1]+2;
                        if(i<n1&&j>=n1)ans=max(ans,dp[i][j]);
                    }
                }
                else{
                    if(i+1<n)dp[i][j]=max(dp[i][j],dp[i+1][j]);
                    if(j)dp[i][j]=max(dp[i][j],dp[i][j-1]);
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

    string word1="aa";
    string word2="bb";
    auto ans=sol.longestPalindrome(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
