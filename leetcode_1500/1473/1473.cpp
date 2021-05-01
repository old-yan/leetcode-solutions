#include "utils.h"

int _dp[101][21][102];
auto dp=_dp+1;

class Solution {
    int __houses[101]={0},m,n,target;
    int* houses=__houses+1;
    vvi cost;
    int dfs(int idx,int cur,int types){
        if(dp[idx][cur][types]>=0)return dp[idx][cur][types];
        if(houses[idx]&&cur!=houses[idx])return dp[idx][cur][types]=0x3f3f3f3f;
        int res=0x3f3f3f3f;
        int extra=houses[idx]==cur?0:cost[idx][cur-1];
        if(idx==m-1){
            if(types==1)res=0;
        }
        else if(types){
            FOR(nxt,1,n+1){
                chmin(res,dfs(idx+1,nxt,types-(cur!=nxt)));
            }
        }
        else chmin(res,dfs(idx+1,cur,0));
        return dp[idx][cur][types]=res+extra;
    }
public:
    int minCost(vector<int>& _houses, vector<vector<int>>& _cost, int _m, int _n, int _target) {
        m=_m,n=_n,target=_target;
        REP(i,m)houses[i]=_houses[i];
        cost=_cost;
        memset(_dp,0xff,sizeof(_dp));
        int ans=dfs(-1,0,target+1);
        return ans>=0x3f3f3f3f?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi houses{3,1,2,3};
    vvi cost=makevvi("[[1,1,1],[1,1,1],[1,1,1],[1,1,1]]");
    int m=4;
    int n=3;
    int target=3;
    auto ans=sol.minCost(houses,cost,m,n,target);
    DBG(ans);

    system("pause");
    return 0;
}
