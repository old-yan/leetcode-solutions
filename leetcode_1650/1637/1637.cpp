#include "utils.h"

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(ALL(points));
        int ans=0;
        for(int i=0,j;i<points.size();i=j){
            for(j=i+1;j<points.size()&&points[j][0]==points[i][0];j++);
            if(j<points.size())chmax(ans,points[j][0]-points[i][0]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[8,7],[9,9],[7,4],[9,7]]");
    auto ans=sol.maxWidthOfVerticalArea(points);
    DBG(ans);

    system("pause");
    return 0;
}
