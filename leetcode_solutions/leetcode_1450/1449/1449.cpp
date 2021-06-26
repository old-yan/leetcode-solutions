#include "utils.h"

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        pair<int,int>dp[10][target+1];//位数、本位数
        memset(dp,0,sizeof(dp));
        FOR(i,1,10){
            int c=cost[i-1];
            REP(j,target+1){
                dp[i][j]={dp[i-1][j].first,0};
                if(j==c||(j>c&&dp[i][j-c].first)){
                    chmax(dp[i][j],{dp[i][j-c].first+1,dp[i][j-c].second+1});
                }
            }
        }
        if(!dp[9][target].first)return "0";
        string ans;
        FORR(i,9,1){
            ans+=string(dp[i][target].second,'0'+i);
            target-=dp[i][target].second*cost[i-1];
        }
        sort(ALLR(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi cost{4,3,2,5,6,7,2,5,5};
    int target=9;
    auto ans=sol.largestNumber(cost,target);
    DBG(ans);

    system("pause");
    return 0;
}
