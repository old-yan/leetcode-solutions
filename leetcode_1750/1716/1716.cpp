#include "utils.h"

class Solution {
public:
    int totalMoney(int n) {
        int week=n/7;
        int ans=(28+28+(week-1)*7)*week/2;
        int rest=n%7;
        ans+=(1+week+1+week+rest-1)*rest/2;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.totalMoney(n);
    DBG(ans);

    system("pause");
    return 0;
}
