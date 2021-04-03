#include "utils.h"

class Solution {
    int edge[50][50][2];
    bool isVertical(int dx1,int dy1,int dx2,int dy2){
        return dx1*dx2+dy1*dy2==0;
    }
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n=points.size();
        set<pair<int,int>>S;
        REP(i,n)S.emplace(points[i][0],points[i][1]);
        REP(i,n){
            REP(j,n){
                edge[i][j][0]=points[j][0]-points[i][0];
                edge[i][j][1]=points[j][1]-points[i][1];
            }
        }
        int ans=INT_MAX;
        REP(i,n){
            REP(j,n){
                if(j==i)continue;
                int dx1=edge[i][j][0],dy1=edge[i][j][1];
                REP(k,j){
                    if(k==i)continue;
                    int dx2=edge[i][k][0],dy2=edge[i][k][1];
                    if(isVertical(dx1,dy1,dx2,dy2)){
                        if(S.count({points[i][0]+dx1+dx2,points[i][1]+dy1+dy2})){
                            ans=min(ans,abs(dx1*dy2-dx2*dy1));
                        }
                    }
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,2],[2,1],[1,0],[0,1]]");
    auto ans=sol.minAreaFreeRect(points);
    DBG(ans);

    system("pause");
    return 0;
}
