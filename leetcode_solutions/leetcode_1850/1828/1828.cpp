#include "utils.h"

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vi ans;
        for(auto&q:queries){
            int x0=q[0],y0=q[1],r=q[2];
            int cnt=0;
            for(auto&p:points){
                int x=p[0],y=p[1];
                if(pow(x-x0,2)+pow(y-y0,2)<=r*r)cnt++;
            }
            ans.pb(cnt);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,3],[3,3],[5,3],[2,2]]");
    vvi queries=makevvi("[[2,3,1],[4,3,1],[1,1,2]]");
    auto ans=sol.countPoints(points,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
