#include "utils.h"

class Solution {
public:
    bool isMatch(string s, string _p) {
        string p;
        for(int i=0,j;i<_p.size();){
            if(_p[i]!='*')p+=_p[i++];
            else{
                while(_p[++i]=='*');
                p+='*';
            }
        }
        int dp[s.size()+2][p.size()+2];
        memset(dp,0,sizeof(dp));
        dp[s.size()][p.size()]=1;
        FORR(i2,p.size()-1,0){
            if(isalpha(p[i2])){
                REP(i1,s.size())dp[i1][i2]=s[i1]==p[i2]&&dp[i1+1][i2+1];
            }
            else if(p[i2]=='?'){
                REP(i1,s.size())dp[i1][i2]=dp[i1+1][i2+1];
            }
            else{
                int b=0;
                REPR(i1,s.size()){
                    if(dp[i1][i2+1])b=1;
                    dp[i1][i2]=b;
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

    string s="abceb";
    string p="a*b";
    auto ans=sol.isMatch(s,p);
    DBG(ans);

    system("pause");
    return 0;
}
