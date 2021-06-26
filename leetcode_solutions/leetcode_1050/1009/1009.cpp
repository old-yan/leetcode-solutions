#include "utils.h"

class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N)return 1;
        int lead_zero=__builtin_clz(N);
        return (~(N<<lead_zero))>>lead_zero;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=7;
    auto ans=sol.bitwiseComplement(N);
    DBG(ans);

    system("pause");
    return 0;
}
