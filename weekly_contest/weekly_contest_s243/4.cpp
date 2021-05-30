#include "utils.h"

class Solution {
public:
    //本题一看数据范围，就知道用动态规划
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n=dist.size();
        //定义dp[i+1][j]为i以及i之前的路，使用j次技能，所消耗的最小时间。
        double dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        REP(i,n){
            double t=(double)dist[i]/speed;
            dp[i+1][0]=ceil(dp[i][0]+t-EPS);
            FOR(j,1,n+1){
                //转移的时候有两种选择，一种是最后的任务用技能，另一种选择是在之前用光技能，最后的任务不用技能。
                dp[i+1][j]=min(dp[i][j-1]+t,ceil(dp[i][j]+t-EPS));
            }
        }
        REP(ans,n){
            if(dp[n][ans]<=hoursBefore)return ans;
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
    int hourbefore=2;
    auto ans=sol.minSkips(dist,speed,hourbefore);
    DBG(ans);

    system("pause");
    return 0;
}
