#include "utils.h"

class Solution {
    #define X 40
    string s;
    vector<vector<string>>ans;
    bool dp[X][X];
    void dfs(int cur,vector<string>&path){
        if(cur==s.size()){
            ans.pb(path);
        }
        else{
            FOR(i,cur+1,s.size()+1){
                if(dp[cur][i-1]){
                    path.pb(s.substr(cur,i-cur));
                    dfs(i,path);
                    path.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string _s) {
        s=_s;
        REP(i,s.size()){
            REP(j,s.size()-i){
                if(i<=2)dp[j][j+i]=s[j]==s[j+i];
                else dp[j][j+i]=s[j]==s[j+i]&&dp[j+1][j+i-1];
            }
        }
        vector<string>path;
        dfs(0,path);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aab";
    auto ans=sol.partition(s);
    DBGVV(ans);

    system("pause");
    return 0;
}
