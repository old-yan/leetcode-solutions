#include "utils.h"

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(ALL(points));
        int n=points.size();
        int ans=0;
        for(int i=0,j;i<n;i=j){
            int pos=points[i][1];
            for(j=i+1;j<n&&points[j][0]<=pos;j++){
                chmin(pos,points[j][1]);
            }
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points{
        {10,16},{2,8},{1,6},{7,12}
    };
    auto ans=sol.findMinArrowShots(points);
    DBG(ans);

    system("pause");
    return 0;
}
