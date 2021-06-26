#include "utils.h"

class Solution {
    string s1,s2,s3;
    int m,n;
    int dp[201][201];
    bool fun(int l1,int l2){
        if(dp[l1][l2]>=0)return dp[l1][l2];
        if(l1&&s1[l1-1]==s3[l1+l2-1]&&fun(l1-1,l2))return dp[l1][l2]=1;
        if(l2&&s2[l2-1]==s3[l1+l2-1]&&fun(l1,l2-1))return dp[l1][l2]=1;
        return dp[l1][l2]=0;
    }
public:
    bool isInterleave(string _s1, string _s2, string _s3) {
        s1=_s1,s2=_s2,s3=_s3;
        m=s1.size(),n=s2.size();
        if(m+n!=s3.size())return false;
        memset(dp,0xff,sizeof(dp));
        dp[0][0]=1;
        return fun(m,n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="aabcc";
    string s2="dbbca";
    string s3="aadbbcbcac";
    auto ans=sol.isInterleave(s1,s2,s3);
    DBG(ans);

    system("pause");
    return 0;
}
