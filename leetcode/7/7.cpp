#include "utils.h"
#include <algorithm>

class Solution {
public:
    int reverse(int _x) {
        int signal=1;
        ll x=_x;
        if(x<0){
            signal=-1;
            x*=-1;
        }
        string s=i2s(x);
        std::reverse(ALL(s));
        ll y=s2i(s);
        if(y>INT_MAX||y<INT_MIN)return 0;
        else return signal*y;
    }
};

int main()
{
    Solution sol;

    int x=-123;
    auto ans=sol.reverse(x);
    DBG(ans);

    system("pause");
    return 0;
}
