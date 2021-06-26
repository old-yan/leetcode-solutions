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

    int a=1;
    int b=1;
    auto ans=sol.add(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
