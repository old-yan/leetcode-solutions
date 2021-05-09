#include "utils.h"

class Solution {
public:
    int countOdds(int low, int high) {
        return (high-low)/2+(low%2||high%2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int low=3;
    int high=7;
    auto ans=sol.countOdds(low,high);
    DBG(ans);

    system("pause");
    return 0;
}
