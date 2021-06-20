#include "utils.h"

class Solution {
public:
    int exchangeBits(int num) {
        int a=0xaaaaaaaa&num,b=0x55555555&num;
        return (b<<1)+(a>>1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=2;
    auto ans=sol.exchangeBits(num);
    DBG(ans);

    system("pause");
    return 0;
}
