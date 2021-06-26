#include "utils.h"

class Solution {
    int dp[1001][1001];
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size(),n2=str2.size();
        FOR(i,1,n1+1){
            FOR(j,1,n2+1){
                if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans;
        int i=n1,j=n2;
        while(i&&j){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[--i];
                j--;
            }
            else if(dp[i][j]==dp[i-1][j]){
                ans+=str1[--i];
            }
            else ans+=str2[--j];
        }
        while(i)ans+=str1[--i];
        while(j)ans+=str1[--j];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string str1="abac";
    string str2="cab";
    auto ans=sol.shortestCommonSupersequence(str1,str2);
    DBG(ans);

    system("pause");
    return 0;
}
