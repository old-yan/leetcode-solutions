#include "utils.h"

class Solution {
public:
    //二重循环，对每个圆，判断每个点的距离远近
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vi ans;
        for(auto&q:queries){
            int cnt=0,x0=q[0],y0=q[1],r=q[2]*q[2];
            for(auto&p:points){
                int x=p[0]-x0,y=p[1]-y0;
                int dis=x*x+y*y;
                if(dis<=r)cnt++;
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

    vvi points=makevvi("[[1,1],[2,2],[3,3],[4,4],[5,5]]");
    vvi queries=makevvi("[[1,2,2],[2,2,2],[4,3,2],[4,3,3]]");
    auto ans=sol.countPoints(points,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
