#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(!n)return 0;
        int maxafter[n];
        REPR(i,n-1){
            if(i==n-1)maxafter[i]=prices[i];
            else maxafter[i]=max(maxafter[i+1],prices[i]);
        }
        int ans=0;
        REP(i,n){
            chmax(ans,maxafter[i]-prices[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi prices{7,1,5,3,6,4};
    auto ans=sol.maxProfit(prices);
    DBG(ans);

    system("pause");
    return 0;
}
