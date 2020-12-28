#include "utils.h"

class Solution {
public:
    string numberToWords(int num) {

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=1234567891;
    auto ans=sol.numberToWords(num);
    DBG(ans);

    system("pause");
    return 0;
}
