#include "utils.h"

class Solution {
public:
    int findComplement(int num) {
        int lead_zero=__builtin_clz(num);
        return (~(num<<lead_zero))>>lead_zero;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=5;
    auto ans=sol.findComplement(num);
    DBG(ans);

    system("pause");
    return 0;
}
