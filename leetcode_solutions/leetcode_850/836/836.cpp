#include "utils.h"

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        ll x1=rec1[0],y1=rec1[1],x2=rec1[2],y2=rec1[3];
        ll x3=rec2[0],y3=rec2[1],x4=rec2[2],y4=rec2[3];
        return max(x2,x4)-min(x1,x3)<x2-x1+x4-x3&&max(y2,y4)-min(y1,y3)<y2-y1+y4-y3;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi rec1{0,0,2,2};
    vi rec2{1,1,3,3};
    auto ans=sol.isRectangleOverlap(rec1,rec2);
    DBG(ans);

    system("pause");
    return 0;
}
