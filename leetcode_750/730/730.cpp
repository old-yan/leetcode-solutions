#include "utils.h"

class Solution {
    #define MOD 1000000007
public:
    int countPalindromicSubsequences(string S) {
        int n=S.size();
        long dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(S[j]!=S[j+i]){
                    dp[j][j+i]=(dp[j][j+i-1]+dp[j+1][j+i]-dp[j+1][j+i-1]+MOD)%MOD;
                }
                else if(!i){
                    dp[j][j+i]=1;
                }
                else{
                    int left=S.find_first_of(S[j],j+1);
                    int right=S.find_last_of(S[j],j+i-1);
                    if(left==j+i){
                        dp[j][j+i]=(dp[j+1][j+i-1]*2+2)%MOD;
                    }
                    else if(left==right){
                        dp[j][j+i]=(dp[j+1][j+i-1]*2+1)%MOD;
                    }
                    else{
                        dp[j][j+i]=(dp[j+1][j+i-1]*2-dp[left+1][right-1]+MOD)%MOD;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="abba";
    auto ans=sol.countPalindromicSubsequences(S);
    DBG(ans);

    system("pause");
    return 0;
}
