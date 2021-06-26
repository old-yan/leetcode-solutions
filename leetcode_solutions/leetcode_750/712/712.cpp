#include "utils.h"

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        REPR(i,m-1){
            REPR(j,n-1){
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                if(s1[i]==s2[j])chmax(dp[i][j],dp[i+1][j+1]+int(s[i])*2);
            }
        }
        return accumulate(ALL(s1),int(0))+accumulate(ALL(s2),int(0))-dp[0][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="sea";
    string s2="eat";
    auto ans=sol.minimumDeleteSum(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
