#include "utils.h"

class Solution {
public:
    int arrangeCoins(int n) {
        ll low=0,high=70000;
        while(low<high){
            ll mid=(low+high)/2;
            if(mid*(mid+1)/2>n)high=mid;
            else low=mid+1;
        }
        return low-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=8;
    auto ans=sol.arrangeCoins(n);
    DBG(ans);

    system("pause");
    return 0;
}
