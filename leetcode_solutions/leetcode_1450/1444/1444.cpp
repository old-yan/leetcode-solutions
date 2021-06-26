#include "utils.h"

class Solution {
    int m,n,ans=0;
    int presum[51][51]={0};
    ll dp[50][50][10];
    bool visited[50][50][10]={0};
    int rangeSum(int r1,int c1,int r2,int c2){
        return presum[r2+1][c2+1]+presum[r1][c1]-presum[r1][c2+1]-presum[r2+1][c1];
    }
    ll dfs(int r1,int c1,int rest){
        if(visited[r1][c1][rest])return dp[r1][c1][rest];
        visited[r1][c1][rest]=true;
        if(rest==1)return dp[r1][c1][rest]=rangeSum(r1,c1,m-1,n-1)>0;
        ll res=0;
        FOR(c,c1+1,n){
            if(!rangeSum(r1,c1,m-1,c-1))continue;
            if(rangeSum(r1,c,m-1,n-1)<rest-1)break;
            res+=dfs(r1,c,rest-1);
        }
        FOR(r,r1+1,m){
            if(!rangeSum(r1,c1,r-1,n-1))continue;
            if(rangeSum(r,c1,m-1,n-1)<rest-1)break;
            res+=dfs(r,c1,rest-1);
        }
        return dp[r1][c1][rest]=res%MOD;
    }
public:
    int ways(vector<string>& pizza, int k) {
        m=pizza.size(),n=pizza[0].size();
        REP(i,m)REP(j,n)presum[i+1][j+1]=pizza[i][j]=='A';
        REP(i,m)partial_sum(presum[i+1],presum[i+2],presum[i+1]);
        REP(i,m)REP(j,n)presum[i+1][j+1]+=presum[i][j+1];
        return dfs(0,0,k);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>pizza{"A..","AAA","..."};
    int k=3;
    auto ans=sol.ways(pizza,k);
    DBG(ans);

    system("pause");
    return 0;
}
