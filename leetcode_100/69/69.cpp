#include "utils.h"

class Solution {
    int firstbigger(ll x){
        ll low = 0;
        ll high = x+1;
        while (low<high)
        {
            ll mid = (high + low) / 2;
            if (mid*mid>x)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
public:
    int mySqrt(int x) {
        return firstbigger(x)-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int x=8;
    auto ans=sol.mySqrt(x);
    DBG(ans);

    system("pause");
    return 0;
}
