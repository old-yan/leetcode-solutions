#include "utils.h"

class Solution {
public:
    string convertToBase7(int num) {
        return i2s(num,7);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=100;
    auto ans=sol.convertToBase7(num);
    DBG(ans);

    system("pause");
    return 0;
}
