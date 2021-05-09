#include "utils.h"

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vi ans=prices;
        stack<int>S;
        REPR(i,prices.size()-1){
            while(S.size()&&S.top()>prices[i])S.pop();
            if(S.size())ans[i]=prices[i]-S.top();
            while(S.size()&&S.top()==prices[i])S.pop();
            S.emplace(prices[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi prices{8,4,6,2,3};
    auto ans=sol.finalPrices(prices);
    DBGV(ans);

    system("pause");
    return 0;
}
