#include "utils.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        while(n>=5){
            cnt+=n/5;
            n/=5;
        }
        return cnt;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.trailingZeroes(n);
    DBG(ans);

    system("pause");
    return 0;
}
