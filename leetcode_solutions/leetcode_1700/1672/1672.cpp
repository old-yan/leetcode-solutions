#include "utils.h"

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size();
        int sum[m];
        REP(i,m)sum[i]=accumulate(ALL(accounts[i]),0);
        return *max_element(sum,sum+m);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi accounts=makevvi("[[1,2,3],[3,2,1]]");
    auto ans=sol.maximumWealth(accounts);
    DBG(ans);

    system("pause");
    return 0;
}
