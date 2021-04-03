#include "utils.h"

class RecentCounter {
    queue<int>Q;
public:
    RecentCounter() {}
    int ping(int t) {
        Q.push(t);
        while(Q.front()<t-3000)Q.pop();
        return Q.size();
    }
};

int main()
{
    cout<<boolalpha;

	RecentCounter*obj=new RecentCounter();
	obj->ping(1);
	obj->ping(100);
	obj->ping(3001);
	obj->ping(3002);

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