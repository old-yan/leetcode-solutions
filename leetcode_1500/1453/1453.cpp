#include "utils.h"

class Solution {
    bool getCenter(vector<int>&v1,vector<int>&v2,int r,double&x0,double&y0){
        double dx=v2[0]-v1[0],dy=v2[1]-v1[1];
        if(dx*dx+dy*dy>4*r*r)return false;
        double xm=(v1[0]+v2[0])/2.0,ym=(v1[1]+v2[1])/2.0;
        double a=sqrt(dx*dx+dy*dy)/2;
        double b=sqrt(4*r*r-dx*dx-dy*dy)/2;
        x0=xm+dy*b/a/2;
        y0=ym-dx*b/a/2;
        return true;
    }
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int n=points.size();
        int ans=1;
        REP(i,n){
            REP(j,n)if(j!=i){
                double x0,y0;
                if(!getCenter(points[i],points[j],r,x0,y0))continue;
                int cnt=0;
                REP(k,n){
                    cnt+=pow(x0-points[k][0],2)+pow(y0-points[k][1],2)<=r*r;
                }
                chmax(ans,cnt);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[-3,0],[3,0],[2,6],[5,4],[0,9],[7,8]]");
    int r=5;
    auto ans=sol.numPoints(points,r);
    DBG(ans);

    system("pause");
    return 0;
}
