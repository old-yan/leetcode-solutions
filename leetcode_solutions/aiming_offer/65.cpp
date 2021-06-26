#include "utils.h"

class Solution {
public:
    int add(int a, int b) {
        int c[2]={a,b};
        return accumulate(c,c+2,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=15;
    int b=94;
    auto ans=sol.add(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
