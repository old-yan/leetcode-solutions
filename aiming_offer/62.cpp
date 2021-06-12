#include "utils.h"

class Solution {
public:
    int lastRemaining(int n, int m) {
        int cur=0;
        FOR(i,2,n+1){
            cur=(cur+m)%i;
        }
        return cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    int m=3;
    auto ans=sol.lastRemaining(n,m);
    DBG(ans);

    system("pause");
    return 0;
}
