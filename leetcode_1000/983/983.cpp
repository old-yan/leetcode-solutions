#include "utils.h"

class Solution {
    int _dp[430]={0};
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        auto dp=_dp+30;
        memset(dp,0x3f,366*sizeof(int));
        dp[0]=0;
        int cur=0;
        for(int d:days){
            while(cur<d){
                chmin(dp[cur],dp[cur-1]);
                cur++;
            }
            FOR(i,cur,cur+1)chmin(dp[i],dp[i-1]+costs[0]);
            FOR(i,cur,cur+7)chmin(dp[i],dp[i-7]+costs[1]);
            FOR(i,cur,cur+30)chmin(dp[i],dp[i-30]+costs[2]);
            cur++;
        }
        while(cur<=365){
            chmin(dp[cur],dp[cur-1]);
            cur++;
        }
        return dp[365];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi days{1,4,6,7,8,20};
    vi costs{2,7,15};
    auto ans=sol.mincostTickets(days,costs);
    DBG(ans);

    system("pause");
    return 0;
}
