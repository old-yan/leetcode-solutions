#include "utils.h"

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n>1?0.5:1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    auto ans=sol.nthPersonGetsNthSeat(n);
    DBG(ans);

    system("pause");
    return 0;
}
