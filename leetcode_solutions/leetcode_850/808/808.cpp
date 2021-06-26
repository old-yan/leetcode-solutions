#include "utils.h"

class Solution {
public:
    double soupServings(int N) {
        if(N>=5000)return 1;
        int maxn=(N-1)/50+1;
        double ans=0;
        double dp[maxn+1][maxn*4+1];//dp[i][j]表示取i次，A少了j单位
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        REP(i,maxn){
            FOR(j,i,i*4+1){
                int cura=N-j*25,curb=N-(4*i-j)*25;
                if(cura<=0){
                    if(curb<=0)ans+=dp[i][j]/2;
                    else ans+=dp[i][j];
                }
                else if(curb>0){
                    dp[i+1][j+1]+=dp[i][j]/4;
                    dp[i+1][j+2]+=dp[i][j]/4;
                    dp[i+1][j+3]+=dp[i][j]/4;
                    dp[i+1][j+4]+=dp[i][j]/4;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=50;
    auto ans=sol.soupServings(N);
    DBG(ans);

    system("pause");
    return 0;
}
