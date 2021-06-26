#include "utils.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x^y);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int x=1,y=4;
    auto ans=sol.hammingDistance(x,y);
    DBG(ans);

    system("pause");
    return 0;
}
