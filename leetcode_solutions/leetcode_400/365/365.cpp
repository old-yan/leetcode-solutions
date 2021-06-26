#include "utils.h"

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(!z||z==x||z==y)return true;
        return z<=x+y&&z%gcd(x,y)==0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int x=3;
    int y=5;
    int z=4;
    auto ans=sol.canMeasureWater(x,y,z);
    DBG(ans);

    system("pause");
    return 0;
}
