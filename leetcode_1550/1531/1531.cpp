#include "utils.h"

class Solution {
    int num[101];
    void init(){
        num[1]=1;
        FOR(i,2,10)num[i]=2;
        FOR(i,10,100)num[i]=3;
        num[100]=4;
    }
public:
    int getLengthOfOptimalCompression(string&s, int k) {
        init();
        int n=s.size();
        if(k>n/2)return getLengthOfOptimalCompression2(s,k);
        int _dp[n+1][k+1];
        memset(_dp,0x3f,sizeof(_dp));
        auto dp=_dp+1;
        dp[-1][0]=0;
        REP(i,n){
            REP(j,k+1){
                if(j)dp[i][j]=dp[i-1][j-1];
                int same=0,dif=0;
                REPR(l,i){
                    if(s[l]==s[i])same++;
                    else dif++;
                    if(dif>j)break;
                    chmin(dp[i][j],dp[l-1][j-dif]+num[same]);
                }
            }
        }
        return dp[n-1][k];
    }
    int getLengthOfOptimalCompression2(string&s, int k) {
        int n=s.size();
        k=n-k;
        int _dp[n+1][k+1];
        memset(_dp,0x3f,sizeof(_dp));
        auto dp=_dp+1;
        dp[-1][0]=0;
        REP(i,n){
            REP(j,k+1){
                dp[i][j]=dp[i-1][j];
                int same=0,dif=0;
                REPR(l,i){
                    if(s[l]==s[i])same++;
                    else dif++;
                    if(same>j)break;
                    chmin(dp[i][j],dp[l-1][j-same]+num[same]);
                }
            }
        }
        return dp[n-1][k];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abc";
    int k=1;
    auto ans=sol.getLengthOfOptimalCompression(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
