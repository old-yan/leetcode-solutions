#include "utils.h"

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s=word1+word2;
        int n1=word1.size(),n2=word2.size(),n=n1+n2;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        #define a(i)  (i<n1?word1[i]:word2[i-n1])
        int ans=0;
        for(int j=n-1;j>=0;j--){
            for(int i=j;i<n;i++){
                dp[j][i]=1;
                if(j+1<n)dp[j][i]=max(dp[j][i],dp[j+1][i]);
                if(i)dp[j][i]=max(dp[j][i],dp[j][i-1]);
                if(a(j)==a(i)){
                    if(j==i)dp[j][i]=1;
                    else{
                        if(dp[j+1][i-1]+2>=dp[j][i]){
                            dp[j][i]=dp[j+1][i-1]+2;
                            if(i>=n1)ans=max(ans,dp[j][i]);
                        }
                    }
                }
            }
        }
        cout<<ans;
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
