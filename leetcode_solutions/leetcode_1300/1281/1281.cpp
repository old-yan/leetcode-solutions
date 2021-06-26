#include "utils.h"

class Solution {
public:
    int subtractProductAndSum(int n) {
        string s=i2s(n);
        ll sum=0,prod=1;
        for(char c:s){
            sum+=c-'0';
            prod*=(c-'0');
        }
        return prod-sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=111;
    auto ans=sol.subtractProductAndSum(n);
    DBG(ans);

    system("pause");
    return 0;
}
