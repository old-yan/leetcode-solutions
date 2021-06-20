#include "utils.h"

class Solution {
public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        double r1=square1[2]/2.0,r2=square2[2]/2.0;
        double cx1=square1[0]+r1,cy1=square1[1]+r1,cx2=square2[0]+r2,cy2=square2[1]+r2;
        if(cx1==cx2&&cy1==cy2){
            return {cx1,cy1-max(r1,r2),cx2,cy2+max(r1,r2)};
        }
        double dx=cx1-cx2,dy=cy1-cy2;
        vector<pair<double,double>>joins;
        if(abs(dy)>abs(dx)){
            double k=1.0*dx/dy;
            joins.emplace_back(cx1-k*r1,cy1-r1);
            joins.emplace_back(cx1+k*r1,cy1+r1);
            joins.emplace_back(cx2-k*r2,cy2-r2);
            joins.emplace_back(cx2+k*r2,cy2+r2);
        }
        else{
            double k=1.0*dy/dx;
            joins.emplace_back(cx1-r1,cy1-k*r1);
            joins.emplace_back(cx1+r1,cy1+k*r1);
            joins.emplace_back(cx2-r2,cy2-k*r2);
            joins.emplace_back(cx2+r2,cy2+k*r2);
        }
        sort(ALL(joins));
        return {joins[0].first,joins[0].second,joins[3].first,joins[3].second};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi square1{-1, -1, 2};
    vi square2{0, -1, 2};
    auto ans=sol.cutSquares(square1,square2);
    DBGV(ans);

    system("pause");
    return 0;
}
