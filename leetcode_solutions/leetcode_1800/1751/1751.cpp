#include "utils.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vi idxes(n);
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return events[x][1]<events[y][1];});
        int start[n],end[n],profit[n];
        REP(i,n){
            start[i]=events[idxes[i]][0];
            end[i]=events[idxes[i]][1];
            profit[i]=events[idxes[i]][2];
        }
        int dp[n+1][k+1];
        memset(dp,0x80,sizeof(dp));
        dp[0][0]=0;
        REP(i,n){
            dp[i+1][0]=dp[i][0];
            FOR(j,1,k+1){
                int l=lower_bound(end,end+i,start[i])-end;
                dp[i+1][j]=max(dp[i][j],dp[l][j-1]+profit[i]);
            }
        }
        return *max_element(dp[n],dp[n+1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi events=makevvi("[[1,2,4],[3,4,3],[2,3,10]]");
    int k=2;
    auto ans=sol.maxValue(events,k);
    DBG(ans);

    system("pause");
    return 0;
}
