#include "utils.h"

class Solution {
    bool onEdge(vi&start,vi&end,double x,double y){
        double dx1=x-start[0],dy1=y-start[1];
        double dx2=end[0]-x,dy2=end[1]-y;
        return abs(dx1*dy2-dx2*dy1)<EPS&&!(dx1*dx2<0||dy1*dy2<0);
    }
    tuple<double,double,double>getabc(vi&start,vi&end){
        return {start[1]-end[1],end[0]-start[0],start[1]*end[0]-end[1]*start[0]};
    }
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        if(start1>end1)swap(start1,end1);
        if(start2>end2)swap(start2,end2);

        auto [a1,b1,c1]=getabc(start1,end1);
        auto [a2,b2,c2]=getabc(start2,end2);
        if(a1*b2-a2*b1==0){
            if(onEdge(start1,end1,start2[0],start2[1]))return {double(start2[0]),double(start2[1])};
            if(onEdge(start2,end2,start1[0],start1[1]))return {double(start1[0]),double(start1[1])};
            return {};
        }
        else{
            if(!a1){
                swap(a1,a2),swap(b1,b2),swap(c1,c2);
            }
            double k=a2/a1;
            double y=(c2-k*c1)/(b2-k*b1);
            double x=(c1-b1*y)/a1;
            if(onEdge(start1,end1,x,y)&&onEdge(start2,end2,x,y))return {x,y};
            else return {};
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi start1{0,0};
    vi end1{1,0};
    vi start2{1,1};
    vi end2{0,-1};
    auto ans=sol.intersection(start1,end1,start2,end2);
    DBGV(ans);

    system("pause");
    return 0;
}
