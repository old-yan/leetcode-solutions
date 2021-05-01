#include "utils.h"

class Solution {
    tuple<int,int,int> parse(string&date){
        return {s2i(date.substr(0,4)), s2i(date.substr(5,2)), s2i(date.substr(8,2))};
    }
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
public:
    int daysBetweenDates(string date1, string date2) {
        auto [year1,month1,day1]=parse(date1);
        auto [year2,month2,day2]=parse(date2);
        return abs(getday(year1,month1,day1)-getday(year2,month2,day2));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string date1="2019-06-29";
    string date2="2019-06-30";
    auto ans=sol.daysBetweenDates(date1,date2);
    DBG(ans);

    system("pause");
    return 0;
}
