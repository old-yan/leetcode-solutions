#include "utils.h"

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=9;
    auto ans=sol.bulbSwitch(n);
    DBG(ans);

    system("pause");
    return 0;
}
