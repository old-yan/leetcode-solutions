#include "utils.h"

class Solution {
public:
    int dayOfYear(string date) {
        int year=s2i(date.substr(0,4));
        int month=s2i(date.substr(5,2));
        int day=s2i(date.substr(8,2));
        vi days(13,30);
        days[0]=0;
        for(int i:{1,3,5,7,8,10,12})days[i]++;
        if(year%4||(year%100==0&&year%400))days[2]=28;
        else days[2]=29;
        partial_sum(ALL(days),days.begin());
        return days[month-1]+day;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string date="2019-01-09";
    auto ans=sol.dayOfYear(date);
    DBG(ans);

    system("pause");
    return 0;
}
