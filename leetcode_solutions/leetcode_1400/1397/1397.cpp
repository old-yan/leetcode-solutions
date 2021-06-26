#include "utils.h"

class Solution {
    int m,turn[50][26];
    void init(string&evil){
        m=evil.size();
        auto next=getnext(evil);
        REP(i,m){
            string s=evil.substr(0,i);
            REP(j,26){
                string ss=s+char('a'+j);
                for(int ii=0,jj=0;;){
                    if(ii==ss.size()){
                        turn[i][j]=jj;
                        break;
                    }
                    if(jj<0||ss[ii]==evil[jj]){
                        ii++,jj++;
                    }
                    else{
                        jj=next[jj];
                    }
                }
            }
        }
    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        init(evil);
        ll _dp[n+1][3][m+1];
        memset(_dp,0,sizeof(_dp));
        auto dp=_dp+1;
        int dif,t;
        for(dif=0,t=0;dif<n&&s1[dif]==s2[dif];dif++){
            t=turn[t][s1[dif]-'a'];
            if(t==m)return 0;
        }
        if(dif==n)return 1;
        dp[dif][0][turn[t][s1[dif]-'a']]+=1;
        dp[dif][2][turn[t][s2[dif]-'a']]+=1;
        FOR(k,s1[dif]-'a'+1,s2[dif]-'a'){
            dp[dif][1][turn[t][k]]+=1;
        }
        FOR(i,dif+1,n)REP(j,3)REP(k,m){
            if(j==0){
                REP(l,26){
                    if(l<s1[i]-'a')continue;
                    if(l==s1[i]-'a')dp[i][0][turn[k][l]]=(dp[i][0][turn[k][l]]+dp[i-1][0][k])%MOD;
                    else dp[i][1][turn[k][l]]=(dp[i][1][turn[k][l]]+dp[i-1][0][k])%MOD;
                }
            }
            else if(j==2){
                REP(l,26){
                    if(l>s2[i]-'a')break;
                    if(l==s2[i]-'a')dp[i][2][turn[k][l]]=(dp[i][2][turn[k][l]]+dp[i-1][2][k])%MOD;
                    else dp[i][1][turn[k][l]]=(dp[i][1][turn[k][l]]+dp[i-1][2][k])%MOD;
                }
            }
            else{
                REP(l,26){
                    dp[i][1][turn[k][l]]=(dp[i][1][turn[k][l]]+dp[i-1][1][k])%MOD;
                }
            }
        }
        ll ans=0;
        REP(j,3)REP(k,m){
            ans+=dp[n-1][j][k];
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    string s1="aa";
    string s2="da";
    string evil="b";
    auto ans=sol.findGoodStrings(n,s1,s2,evil);
    DBG(ans);

    system("pause");
    return 0;
}
