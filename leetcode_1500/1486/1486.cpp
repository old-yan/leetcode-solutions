#include "utils.h"

class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        REP(i,n){
            ans^=start+i*2;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    int start=3;
    auto ans=sol.xorOperation(n,start);
    DBG(ans);

    system("pause");
    return 0;
}
