#include "utils.h"

class Solution {
    double ans=0;
    double area(int dx1,int dy1,int dx2,int dy2){
        return 0.5*abs(dx1*dy2-dx2*dy1);
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        REP(i,n-2){
            FOR(j,i+1,n-1){
                FOR(k,j+1,n){
                    chmax(ans,area(points[j][0]-points[i][0],points[j][1]-points[i][1],points[k][0]-points[i][0],points[k][1]-points[i][1]));
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[0,0],[0,1],[1,0],[0,2],[2,0]]");
    auto ans=sol.largestTriangleArea(points);
    DBG(ans);

    system("pause");
    return 0;
}
