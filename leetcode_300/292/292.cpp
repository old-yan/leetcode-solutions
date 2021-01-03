#include "utils.h"

class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    auto ans=sol.canWinNim(n);
    DBG(ans);

    system("pause");
    return 0;
}
