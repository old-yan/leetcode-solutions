#include "utils.h"

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        bool increasing[n][n];
        fill(increasing[0],increasing[n],true);
        for(auto&str:strs){
            REP(i,n){
                REP(j,i){
                    if(str[i]<str[j])increasing[j][i]=false;
                }
            }
        }
        int dp[n];
        REP(i,n){
            dp[i]=1;
            REP(j,i){
                if(increasing[j][i])chmax(dp[i],dp[j]+1);
            }
        }
        return n-*max_element(dp,dp+n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>strs{
        "babca","bbazb"
    };
    auto ans=sol.minDeletionSize(strs);
    DBG(ans);

    system("pause");
    return 0;
}
