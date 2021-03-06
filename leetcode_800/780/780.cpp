#include "utils.h"

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        int curx=tx,cury=ty;
        while(curx>=sx&&cury>=sy){
            if(curx==sx&&(cury-sy)%curx==0)return true;
            if(cury==sy&&(curx-sx)%cury==0)return true;
            if(curx>cury){
                curx%=cury;
            }
            else if(cury>curx){
                cury%=curx;
            }
            else break;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int sx=3;
    int sy=3;
    int tx=12;
    int ty=9;
    auto ans=sol.reachingPoints(sx,sy,tx,ty);
    DBG(ans);

    system("pause");
    return 0;
}