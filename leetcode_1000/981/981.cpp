#include "utils.h"

class TimeMap {
    unordered_map<string,vector<pair<int,string>>>M;
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        M[key].emplace_back(timestamp,value);
    }
    string get(string key, int timestamp) {
        if(!M.count(key))return "";
        auto&v=M[key];
        int low=-1,high=v.size()-1;
        while(low<high){
            int mid=(low+high+1)/2;
            if(v[mid].first<=timestamp)low=mid;
            else high=mid-1;
        }
        if(low>=0)return v[low].second;
        else return "";
    }
};

int main()
{
    cout<<boolalpha;

	TimeMap*obj=new TimeMap();
	obj->set("foo","bar",1);
	obj->get("foo",1);
	obj->get("foo",3);
	obj->set("foo","bar2",4);
	obj->get("foo",4);
	obj->get("foo",5);

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