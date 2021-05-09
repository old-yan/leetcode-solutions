#include "utils.h"

class Solution {
    int n,turn[100][100]={0};
    void init(vi&houses){
        sort(ALL(houses));
        n=houses.size();
        REP(i,n){
            FOR(j,i+1,n){
                FOR(k,i+1,n){
                    if(abs(houses[k]-houses[i])>abs(houses[k]-houses[j])){
                        turn[i][j]+=abs(houses[k]-houses[i])-abs(houses[k]-houses[j]);
                    }
                }
            }
        }
    }
public:
    int minDistance(vector<int>& houses, int k) {
        init(houses);
        int dp[n][k];
        memset(dp,0x3f,sizeof(dp));
        int ans=INT_MAX;
        REP(i,n){
            dp[i][0]=accumulate(ALL(houses),0,[&](int x,int y){return x+abs(y-houses[i]);});
            FOR(j,1,k){
                REP(ii,i){
                    chmin(dp[i][j],dp[ii][j-1]-turn[ii][i]);
                }
            }
            chmin(ans,dp[i][k-1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi houses{1,4,8,10,20};
    int k=3;
    auto ans=sol.minDistance(houses,k);
    DBG(ans);

    system("pause");
    return 0;
}
