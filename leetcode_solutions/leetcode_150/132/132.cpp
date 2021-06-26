#include "utils.h"

class Solution {
public:
    int minCut(string s) {
        int dp[s.size()][s.size()];
        REP(i,s.size()){
            REP(j,s.size()-i){
                if(i<=2)dp[j][j+i]=s[j]==s[j+i];
                else dp[j][j+i]=s[j]==s[j+i]&&dp[j+1][j+i-1];
            }
        }
        int minnum[s.size()+1];
        minnum[s.size()]=0;
        REPR(i,s.size()-1){
            minnum[i]=INT_MAX;
            FOR(j,i+1,s.size()+1){
                if(dp[i][j-1]){
                    chmin(minnum[i],minnum[j]+1);
                }
            }
        }
        return minnum[0]-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aab";
    auto ans=sol.minCut(s);
    DBG(ans);

    system("pause");
    return 0;
}
