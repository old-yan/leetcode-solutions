#include "utils.h"

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        sort(ALL(points));
        if(points[0]==points[1]||points[1]==points[2])return false;
        return getDirection(&points[0],&points[1],&points[2])!=1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,1],[2,2],[3,3]]");
    auto ans=sol.isBoomerang(points);
    DBG(ans);

    system("pause");
    return 0;
}
