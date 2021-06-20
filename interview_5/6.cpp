#include "utils.h"

class Solution {
public:
    int convertInteger(int A, int B) {
        return __builtin_popcount(A^B);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int A=29;
    int B=15;
    auto ans=sol.convertInteger(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
