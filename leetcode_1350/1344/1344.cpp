#include "utils.h"

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a=hour%12/12.0+minutes/720.0;
        double b=minutes/60.0;
        double d;
        if(a<b)d=min(b-a,1-b+a);
        else d=min(a-b,1-a+b);
        return 360.0*d;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int hour=12;
    int minutes=30;
    auto ans=sol.angleClock(hour,minutes);
    DBG(ans);

    system("pause");
    return 0;
}
