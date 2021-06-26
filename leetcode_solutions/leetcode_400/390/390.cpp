#include "utils.h"

class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)return 1;
        else{
            return (n-n%2)+2-lastRemaining(n/2)*2;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    auto ans=sol.lastRemaining(n);
    DBG(ans);

    system("pause");
    return 0;
}
