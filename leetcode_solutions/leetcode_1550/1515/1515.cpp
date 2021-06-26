#include "utils.h"

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        auto getDis=[&](double x,double y){
            double cnt=0;
            for(auto&pos:positions){
                cnt+=sqrt(pow(pos[0]-x,2)+pow(pos[1]-x,2));
            }
            return cnt;
        };
        auto getMin=[&](double x){
            double yMin=0,yMax=100;
            while(yMax-yMin>EPS){
                double y1=yMin+(yMax-yMin)/3,y2=yMin+(yMax-yMin)*2/3;
                double dis1=getDis(x,y1),dis2=getDis(x,y2);
                if(dis1<dis2)yMax=y2;
                else yMin=y1;
            }
            return getDis(x,yMin);
        };
        double xMin=0,xMax=100;
        while(xMax-xMin>EPS){
            double x1=xMin+(xMax-xMin)/3,x2=xMin+(xMax-xMin)*2/3;
            double Mindis1=getMin(x1),Mindis2=getMin(x2);
            if(Mindis1<Mindis2)xMax=x2;
            else xMin=x1;
        }
        return getMin(xMin);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi positions=makevvi("[[0,1],[1,0],[1,2],[2,1]]");
    auto ans=sol.getMinDistSum(positions);
    DBG(ans);

    system("pause");
    return 0;
}
