#include "utils.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i*=5){
            ans+=n/i;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=55;
    auto ans=sol.trailingZeroes(55);
    DBG(ans);

    system("pause");
    return 0;
}
