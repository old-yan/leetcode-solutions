#include "utils.h"

class Solution {
    int dp[401];
    int board[401];
    vi pre[401];
public:
    int snakesAndLadders(vector<vector<int>>& _board) {
        int m=_board.size(),n=_board[0].size();
        memset(dp,0x3f,sizeof(dp));
        dp[m*n]=0;
        REP(i,m){
            REP(j,n){
                board[(m-i-1)*n+((m-i-1)%2?n-j:j+1)]=_board[i][j];
            }
        }
        FOR(i,1,m*n){
            FOR(j,i+1,min((ll)m*n+1,i+7)){
                if(board[j]<0)pre[j].pb(i);
                else pre[board[j]].pb(i);
            }
        }
        queue<int>Q;
        Q.push(m*n);
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            for(int a:pre[p]){
                if(chmin(dp[a],dp[p]+1)){
                    Q.push(a);
                }
            }
        }
        return dp[1]==0x3f3f3f3f?-1:dp[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi board=makevvi("[[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]");
    auto ans=sol.snakesAndLadders(board);
    DBG(ans);

    system("pause");
    return 0;
}
