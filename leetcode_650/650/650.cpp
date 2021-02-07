#include "utils.h"

class Solution {
public:
    int minSteps(int n) {
        vi factors=getFactor(n);
        int sum=0;
        for(int a:factors)sum+=a;
        return sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.minSteps(n);
    DBG(ans);

    system("pause");
    return 0;
}
