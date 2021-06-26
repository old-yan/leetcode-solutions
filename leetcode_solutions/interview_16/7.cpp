#include "utils.h"

class Solution {
public:
    int maximum(int a, int b) {
        return max(a,b);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=1;
    int b=2;
    auto ans=sol.maximum(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
