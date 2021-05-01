#include "utils.h"

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(ALL(horizontalCuts));
        int m=h-horizontalCuts.back();
        adjacent_difference(ALL(horizontalCuts),horizontalCuts.begin());
        chmax(m,*max_element(ALL(horizontalCuts)));
        sort(ALL(verticalCuts));
        int n=w-verticalCuts.back();
        adjacent_difference(ALL(verticalCuts),verticalCuts.begin());
        chmax(n,*max_element(ALL(verticalCuts)));
        return (ll)m*n%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int h=5;
    int w=4;
    vi horizontalCuts{1,2,4};
    vi verticalCuts{1,3};
    auto ans=sol.maxArea(h,w,horizontalCuts,verticalCuts);
    DBG(ans);

    system("pause");
    return 0;
}
