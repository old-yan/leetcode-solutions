#include "utils.h"

class Solution {
    int getday(int year,int month,int day){
        auto isLeap=[](int year){
            if(year%400==0)return true;
            if(year%100==0)return false;
            if(year%4==0)return true;
            return false;
        };
        int day_in_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int res=0;
        for(int i=1;i<year;i++)res+=isLeap(i)?366:365;
        if(isLeap(year))day_in_month[1]++;
        for(int j=0;j<month-1;j++)res+=day_in_month[j];
        res+=day;
        return res;
    }
    string s[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
public:
    string dayOfTheWeek(int day, int month, int year) {
        //1970/12/31 Thursday
        return s[(4+getday(year,month,day)-getday(1970,12,31))%7];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int day=31;
    int month=8;
    int year=2019;
    auto ans=sol.dayOfTheWeek(day,month,year);
    DBG(ans);

    system("pause");
    return 0;
}
