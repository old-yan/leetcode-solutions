#include "utils.h"

class Solution {
public:
    //遍历搜索即可
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ansidx=-1,ansdis=INT_MAX;
        for(int i=0;i<points.size();i++){
            int xi=points[i][0];
            int yi=points[i][1];
            //无效点直接排除
            if(xi!=x&&yi!=y)continue;
            //有效点计算曼哈顿距离，并尝试替换答案
            int dis=abs(xi-x)+abs(yi-y);
            if(dis<ansdis){
                ansdis=dis;
                ansidx=i;
            }
        }
        return ansidx;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int x=3;
    int y=4;
    vvi points=makevvi("[[1,2],[3,1],[2,4],[2,3],[4,4]]");
    auto ans=sol.nearestValidPoint(x,y,points);
    DBG(ans);

    system("pause");
    return 0;
}
