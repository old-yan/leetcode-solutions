#include "utils.h"

class Solution {
    ll sum[30][30];
    ll dp[30][30];
    int n,K;
    ll dfs(int l,int r,int rest){
        if(!rest){
            return dp[l][r];
        }
        else{
            ll res=0x3f3f3f3f;
            for(int i=l+1;i<=r;i+=K-1){
                chmin(res,dp[l][i-1]+dfs(i,r,rest-1));
            }
            return res;
        }
    }
public:
    int mergeStones(vector<int>& stones, int _K) {
        n=stones.size();
        K=_K;
        REP(i,n){
            int cnt=0;
            FOR(j,i,n){
                cnt+=stones[j];
                sum[i][j]=(j-i)%(K-1)?0x3f3f3f3f:cnt;
            }
        }
        REP(i,n){
            REP(j,n-i){
                dp[j][j+i]=i?sum[j][j+i]+dfs(j,j+i,K-1):0;
            }
        }
        return dp[0][n-1]>=0x3f3f3f3f?-1:dp[0][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{3,5,1,2,6};
    int K=3;
    auto ans=sol.mergeStones(stones,K);
    DBG(ans);

    system("pause");
    return 0;
}
