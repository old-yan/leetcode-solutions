#include "utils.h"

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int sum[n][n];
        memset(sum,0,sizeof(sum));
        REP(i,n){
            FOR(j,i,n){
                sum[i][j]=(j?sum[i][j-1]:0)+stoneValue[j];
            }
        }
        int dp[n][n],beginMax[n][n],endMax[n][n],cursor[n];
        memset(dp,0,sizeof(dp));
        memset(beginMax,0,sizeof(beginMax));
        memset(endMax,0,sizeof(endMax));
        iota(cursor,cursor+n,0);
        REP(i,n){
            REP(j,n-i){
                int&k=cursor[j];
                while(sum[j][k]*2<sum[j][j+i])k++;
                dp[j][j+i]=0;
                if(k>j)chmax(dp[j][j+i],beginMax[j][k-1]);
                if(sum[j][k]*2>sum[j][j+i]){
                    if(k<j+i)chmax(dp[j][j+i],endMax[k+1][j+i]);
                }
                else{
                    if(k+1<j+i)chmax(dp[j][j+i],endMax[k+2][j+i]);
                }
                if(sum[j][k]*2==sum[j][j+i]){
                    chmax(dp[j][j+i],max(beginMax[j][k],endMax[k+1][j+i]));
                }
                beginMax[j][j+i]=max(j+i?beginMax[j][j+i-1]:0,dp[j][j+i]+sum[j][j+i]);
                endMax[j][j+i]=max(j+1<n?endMax[j+1][j+i]:0,dp[j][j+i]+sum[j][j+i]);
            }
        }
        return dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stoneValue{6,2,3,4,5,5};
    auto ans=sol.stoneGameV(stoneValue);
    DBG(ans);

    system("pause");
    return 0;
}
