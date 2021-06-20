#include "utils.h"

class Solution {
public:
    //先转换为一天中的第几分钟，然后start向上取整，end向下取整，这样就好算了
    int numberOfRounds(string startTime, string finishTime) {
        int start=s2i(startTime.substr(0,2))*60+s2i(startTime.substr(3,2));
        int end=s2i(finishTime.substr(0,2))*60+s2i(finishTime.substr(3,2));
        if(start>end)end+=1440;
        start=ceil(start/15.0)*15;
        end=floor(end/15.0)*15;
        return (end-start)/15;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string startTime="12:01";
    string finishTime="12:44";
    auto ans=sol.numberOfRounds(startTime,finishTime);
    DBG(ans);

    system("pause");
    return 0;
}
