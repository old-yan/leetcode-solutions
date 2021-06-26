#include "utils.h"

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        FOR(i,1,points.size()){
            int dx=points[i][0]-points[i-1][0],dy=points[i][1]-points[i-1][1];
            ans+=max(abs(dx),abs(dy));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,1],[3,4],[-1,0]]");
    auto ans=sol.minTimeToVisitAllPoints(points);
    DBG(ans);

    system("pause");
    return 0;
}
