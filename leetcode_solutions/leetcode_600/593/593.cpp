#include "utils.h"

class Solution {
    bool fun(vi&p,vi&opp,vi&q1,vi&q2){
        if(p[0]+opp[0]!=q1[0]+q2[0])return false;
        if(p[1]+opp[1]!=q1[1]+q2[1])return false;
        if(p==q1)return false;
        if(p==q2)return false;
        int x1=p[0]-q1[0],y1=p[1]-q1[1];
        int x2=p[0]-q2[0],y2=p[1]-q2[1];
        bool b1=x1*x2+y1*y2==0;
        bool b2=x1*x1+y1*y1==x2*x2+y2*y2;
        return b1&&b2;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return fun(p1,p2,p3,p4)||fun(p1,p3,p2,p4)||fun(p1,p4,p2,p3);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi p1{1,0};
    vi p2{-1,0};
    vi p3{0,1};
    vi p4{0,-1};
    auto ans=sol.validSquare(p1,p2,p3,p4);
    DBG(ans);

    system("pause");
    return 0;
}
