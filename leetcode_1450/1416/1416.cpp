#include "utils.h"

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n=s.size();
        int _dp[n+1];
        memset(_dp,0,sizeof(_dp));
        auto dp=_dp+1;
        dp[-1]=1;
        REP(i,n)if(s[i]!='0'){
            ll cur=0;
            FOR(j,i,n){
                cur=cur*10+(s[j]-'0');
                if(cur>k)break;
                dp[j]=(dp[j]+dp[i-1])%MOD;
            }
        }
        return dp[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="1000";
    int k=10000;
    auto ans=sol.numberOfArrays(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
