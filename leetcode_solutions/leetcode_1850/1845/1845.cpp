#include "utils.h"

class SeatManager {
    priority_queue<int,vi,greater<int>>Q;
public:
    SeatManager(int n) {
        FOR(i,1,n+1){
            Q.push(i);
        }
    }
    int reserve() {
        auto p=Q.top();
        Q.pop();
        return p;
    }    
    void unreserve(int seatNumber) {
        Q.push(seatNumber);
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