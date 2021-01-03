#include "utils.h"

class Solution {
    vi coins;
    int ans=INT_MAX;
    void dfs(int i,int rest,int num){
        if(i==coins.size()){
            if(!rest)chmin(ans,num);
        }
        else{
            int j=rest/coins[i];
            rest%=coins[i];
            while(true){
                if(num+j>=ans)break;
                dfs(i+1,rest,num+j);
                if(--j<0)break;
                rest+=coins[i];
            }
        }
    }
public:
    int coinChange(vector<int>&_coins, int amount) {
        coins=_coins;
        sort(ALL(coins),greater<int>());
        dfs(0,amount,0);
        return ans==INT_MAX?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi coins{1,2,5};
    int amount=11;
    auto ans=sol.coinChange(coins,amount);
    DBG(ans);

    system("pause");
    return 0;
}
