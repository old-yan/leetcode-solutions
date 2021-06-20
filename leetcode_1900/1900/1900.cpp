#include "utils.h"

pair<int,int>dp[29][29][29];
auto _initial=[](){
    memset(dp,0xff,sizeof(dp));
    return 0;
}();
void update(pair<int,int>&x,pair<int,int>&&y){
    chmin(x.first,y.first+1);
    chmax(x.second,y.second+1);
}
pair<int,int> dfs(int n,int fi,int se){
    if(dp[n][fi][se].first>=0)return dp[n][fi][se];
    if(fi+se==n+1)return dp[n][fi][se]={1,1};
    if(fi+se>n+1)return dp[n][fi][se]=dfs(n,n+1-se,n+1-fi);
    auto&res=dp[n][fi][se];
    res={INT_MAX,INT_MIN};
    if(se<=(n+1)/2){
        int A=fi-1,B=se-fi-1,C=(n-se*2+1)/2;
        REP(a,A+1){
            REP(b,B+1){
                update(res,dfs((n+1)/2,a+1,a+b+2));
            }
        }
    }
    else{
        int A=fi-1,B=n-se-fi,C=(se*2-n-1)/2;
        REP(a,A+1){
            REP(b,B+1){
                update(res,dfs((n+1)/2,a+1,a+b+C+2));
            }
        }
    }
    return res;
}

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        auto ans=dfs(n,firstPlayer,secondPlayer);
        return {ans.first,ans.second};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=11;
    int firstPlayer=2;
    int secondPlayer=4;
    auto ans=sol.earliestAndLatest(n,firstPlayer,secondPlayer);
    DBGV(ans);

    system("pause");
    return 0;
}
