#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBefore=INT_MAX;
        ll ans=0;
        for(int a:prices){
            chmax(ans,(ll)a-minBefore);
            chmin(minBefore,a);
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
