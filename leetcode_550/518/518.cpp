#include "utils.h"

class Solution {
    vi coins;
    int dp[5][51];
    int fun(int cur,int rest){
        if(cur<0)return rest?0:1;
        if(dp[cur][rest]>=0)return dp[cur][rest];
        int&val=dp[cur][rest];
        val=0;
        int coin=coins[cur];
        do{
            val+=fun(cur-1,rest);
            rest-=coin;
        }while(rest>=0);
        return val;
    }
public:
    int change(int amount, vector<int>&_coins) {
        coins=_coins;
        memset(dp,0xff,sizeof(dp));
        return fun(coins.size()-1,amount);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int amount=5;
    vi coins{1,2,5};
    auto ans=sol.change(amount,coins);
    DBG(ans);

    system("pause");
    return 0;
}
