#include "utils.h"

class SeatManager {
    //使用set作为管理空闲座位的数据结构
    set<int>seats;
public:
    //初始化时将所有空闲座位放入set
    SeatManager(int n) {
        FOR(i,1,n+1)seats.insert(i);
    }
    //预约set里最小的座位
    int reserve() {
        int res=*seats.begin();
        seats.erase(seats.begin());
        return res;
    }
    //将指定座位返还到set里
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

int main()
{
    cout<<boolalpha;

	SeatManager*obj=new SeatManager(5);
	obj->reserve();
	obj->reserve();
	obj->unreserve(2);
	obj->reserve();
	obj->reserve();
	obj->reserve();
	obj->reserve();
	obj->unreserve(5);

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