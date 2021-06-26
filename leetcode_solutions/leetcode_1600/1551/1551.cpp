#include "utils.h"

class Solution {
public:
    int minOperations(int n) {
        if(n%2)return (n/2+1)*(n/2);
        else return n/2*(n/2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    auto ans=sol.minOperations(n);
    DBG(ans);

    system("pause");
    return 0;
}
