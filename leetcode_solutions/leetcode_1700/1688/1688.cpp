#include "utils.h"

class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.numberOfMatches(n);
    DBG(ans);

    system("pause");
    return 0;
}
