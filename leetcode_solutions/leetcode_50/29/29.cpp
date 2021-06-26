#include "utils.h"

class Solution {
public:
    int divide(int _dividend, int _divisor) {
        if(_dividend==INT_MIN&&_divisor==-1)return INT_MAX;
        //return _dividend/_divisor;
        int signal=1;
        if(_dividend<0)signal*=-1;
        if(_divisor<0)signal*=-1;
        ll dividend=abs(ll(_dividend)),divisor=abs(ll(_divisor));
        if(dividend<divisor)return 0;
        bitset<32>b;
        REPR(i,31){
            if(dividend>=(divisor<<i)){
                dividend-=(divisor<<i);
                b.set(i);
            }
            if(dividend<divisor)break;
        }
        if(signal>0)return b.to_ulong();
        else return -b.to_ulong();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto ans=sol.divide(INT_MIN,-1);
    DBG(ans);

    system("pause");
    return 0;
}
