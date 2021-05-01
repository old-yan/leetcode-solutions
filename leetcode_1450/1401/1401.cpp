#include "utils.h"

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x1<=x_center&&x_center<=x2&&y1<=y_center&&y_center<=y2){
            return true;
        }
        else if(x1<=x_center&&x_center<=x2){
            return min(abs(y1-y_center),abs(y2-y_center))<=radius;
        }
        else if(y1<=y_center&&y_center<=y2){
            return min(abs(x1-x_center),abs(x2-x_center))<=radius;
        }
        else{
            return min(min(pow(x1-x_center,2)+pow(y1-y_center,2),pow(x1-x_center,2)+pow(y2-y_center,2)),
                min(pow(x2-x_center,2)+pow(y1-y_center,2),pow(x2-x_center,2)+pow(y2-y_center,2)))<=radius*radius;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int radius=1;
    int x_center=0;
    int y_center=0;
    int x1=1;
    int y1=-1;
    int x2=3;
    int y2=1;
    auto ans=sol.checkOverlap(radius,x_center,y_center,x1,y1,x2,y2);
    DBG(ans);

    system("pause");
    return 0;
}
