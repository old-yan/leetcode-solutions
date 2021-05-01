#include "utils.h"

class UndergroundSystem {
    unordered_map<string,int>idmap;
    unordered_map<int,pair<int,int>>onRail;
    unordered_map<int,pair<int,int>>M;
    int getid(const string&s){
        if(!idmap.count(s))return idmap[s]=idmap.size();
        else return idmap[s];
    }
public:
    UndergroundSystem() {}
    void checkIn(int id, const string&stationName, int t) {
        onRail[id]={getid(stationName),t};
    }
    void checkOut(int id, const string&stationName, int t) {
        auto [startStation,startTime]=onRail[id];
        int mark=startStation*10000+getid(stationName);
        if(!M.count(mark))M[mark]={0,0};
        auto find=M.find(mark);
        find->second.first+=t-startTime;
        find->second.second++;
    }
    double getAverageTime(const string&startStation,const string&endStation) {
        auto find=M.find(getid(startStation)*10000+getid(endStation));
        return 1.0*find->second.first/find->second.second;
    }
};

int main()
{
    cout<<boolalpha;

	UndergroundSystem*obj=new UndergroundSystem();
	obj->checkIn(45,"Leyton",3);
	obj->checkIn(32,"Paradise",8);
	obj->checkIn(27,"Leyton",10);
	obj->checkOut(45,"Waterloo",15);
	obj->checkOut(27,"Waterloo",20);
	obj->checkOut(32,"Cambridge",22);
	obj->getAverageTime("Paradise","Cambridge");
	obj->getAverageTime("Leyton","Waterloo");
	obj->checkIn(10,"Leyton",24);
	obj->getAverageTime("Leyton","Waterloo");
	obj->checkOut(10,"Waterloo",38);
	obj->getAverageTime("Leyton","Waterloo");

    system("pause");
    return 0;
}
/*
使用如下正则替换将leetcode测试用例转换为代码
首先将leetcode测试样例复制到代码正文中，把换行符删除，两行合并为一行;
将如下替换使用一次(也可以自己手打)：

\["(.+?)"(.*?)\]\[\[(.*?)\](.*)\]
\t$1*obj=new $1($3);\n[$2][$4]

将如下替换连续使用：

\[,"(.+?)"(.*?)\]\[,\[(.*?)\](.*)\]
\tobj->$1($3);\n[$2][$4]

*/