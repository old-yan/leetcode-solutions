#include "utils.h"

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ansidx=-1,ansdis=INT_MAX;
        REP(i,points.size()){
            auto&p=points[i];
            if(p[0]==x||p[1]==y){
                if(chmin(ansdis,abs(p[0]-x)+abs(p[1]-y))){
                    ansidx=i;
                }
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
