#include "utils.h"

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        ll maxLeft=max(A,E);
        ll minRight=min(C,G);
        ll maxBottom=max(B,F);
        ll minTop=min(D,H);
        return ((ll)C-A)*((ll)D-B)+((ll)G-E)*((ll)H-F)-max((ll)0,minRight-maxLeft)*max((ll)0,minTop-maxBottom);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto ans=sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
    DBG(ans);

    system("pause");
    return 0;
}
