#include "utils.h"

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vi ans(n+1,0);
        for(auto&bk:bookings){
            ans[bk[0]-1]+=bk[2];
            ans[bk[1]]-=bk[2];
        }
        partial_sum(ALL(ans),ans.begin());
        ans.pop_back();
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi bookings=makevvi("[[1,2,10],[2,3,20],[2,5,25]]");
    int n=5;
    auto ans=sol.corpFlightBookings(bookings,n);
    DBGV(ans);

    system("pause");
    return 0;
}
