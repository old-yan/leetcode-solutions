#include "utils.h"

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n=dist.size();
        ll dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        REP(i,n){
            dp[i+1][0]=(dp[i][0]+speed-1)/speed*speed;
            FOR(j,1,n+1){
                dp[i+1][j]=min((dp[i][j]+dist[i]+speed-1)/speed*speed,dp[i][j-1]+dist[i]);
            }
        }
        REP(ans,n+1){
            if(dp[n][ans]<=(ll)speed*hoursBefore)return ans;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi dist{1,3,2};
    int speed=4;
    int hoursBefore=2;
    auto ans=sol.minSkips(dist,speed,hoursBefore);
    DBG(ans);

    system("pause");
    return 0;
}
