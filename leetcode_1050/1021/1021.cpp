#include "utils.h"

class Solution {
public:
    string removeOuterParentheses(string S) {
        int n=S.size();
        int dp[n];
        REP(i,n){
            dp[i]=i?dp[i-1]+(S[i]=='('?1:-1):1;
        }
        string ans;
        REP(i,n){
            if(dp[i]==1){
                if(S[i]==')')ans+=S[i];
            }
            else if(dp[i])ans+=S[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="(()())(())";
    auto ans=sol.removeOuterParentheses(S);
    DBG(ans);

    system("pause");
    return 0;
}
