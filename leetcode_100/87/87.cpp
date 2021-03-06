#include "utils.h"

class Solution {
    #define X 40
    string s1,s2;
    int dp[X][X][X];
    bool fun(int i1,int i2,int l){
        if(dp[i1][i2][l]>=0)return dp[i1][i2][l];
        int num[26]={0};
        FOR(i,i1,i1+l)num[s1[i]-'a']++;
        FOR(i,i2,i2+l)num[s2[i]-'a']--;
        REP(i,26)if(num[i])return dp[i1][i2][l]=false;
        if(l<=3)return dp[i1][i2][l]=true;
        FOR(l1,1,l){
            int l2=l-l1;
            if((fun(i1,i2,l1)&&fun(i1+l1,i2+l1,l2))||(fun(i1,i2+l2,l1)&&fun(i1+l1,i2,l2)))return dp[i1][i2][l]=true;
        }
        return dp[i1][i2][l]=false;
    }
public:
    bool isScramble(string _s1, string _s2) {
        s1=_s1,s2=_s2;
        memset(dp,0xff,sizeof(dp));
        if(s1.size()!=s2.size())return false;
        return fun(0,0,s1.size());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="abc";
    string s2="cab";
    auto ans=sol.isScramble(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}