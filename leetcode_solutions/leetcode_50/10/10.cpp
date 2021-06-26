#include "utils.h"

class Solution {
    string s,p;
    int dp[21][31];
    bool same(char c1,char c2){
        if(c2=='.')return c1!=0;
        return c1==c2;
    }
    bool dfs(int i1,int i2){
        if(i1>s.size())return false;
        if(dp[i1][i2]>=0)return dp[i1][i2];
        if(i2==p.size())return dp[i1][i2]=i1==s.size();
        if(p[i2+1]=='*'){
            FOR(i,i1,s.size()+1){
                if(dfs(i,i2+2))return dp[i1][i2]=true;
                if(!same(s[i],p[i2]))break;
            }
            return dp[i1][i2]=false;
        }
        else return dp[i1][i2]=same(s[i1],p[i2])&&dfs(i1+1,i2+1);
    }
public:
    bool isMatch(string _s, string _p) {
        s=_s;
        p=_p;
        memset(dp,0xff,sizeof(dp));
        dfs(0,0);
        return dp[0][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s= "ssii";
    string p= "s*i";
    auto ans=sol.isMatch(s,p);
    DBG(ans);

    system("pause");
    return 0;
}
