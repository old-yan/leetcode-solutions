#include "utils.h"

class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=38;
    auto ans=sol.addDigits(num);
    DBG(ans);

    system("pause");
    return 0;
}
