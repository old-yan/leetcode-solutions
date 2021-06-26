#include "utils.h"

int dp[30][30];
class Solution {
    string s,p;
    bool same(char x,char y){
        return y=='.'?true:x==y;
    }
    bool dfs(int i,int j){
        if(dp[i][j]>=0)return dp[i][j];
        if(j==p.size())return dp[i][j]=(i==s.size());
        if(p[j+1]=='*'){
            FOR(k,i,s.size()+1){
                if(dfs(k,j+2))return dp[i][j]=true;
                if(same(s[k],p[j]))continue;
                else break;
            }
            return dp[i][j]=false;
        }
        else{
            return dp[i][j]=same(s[i],p[j])&&dfs(i+1,j+1);
        }
    }
public:
    bool isMatch(string _s, string _p) {
        memset(dp,0xff,sizeof(dp));
        s=_s,p=_p;
        return dfs(0,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ab";
    string p=".*";
    auto ans=sol.isMatch(s,p);
    DBG(ans);

    system("pause");
    return 0;
}
