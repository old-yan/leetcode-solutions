#include "utils.h"

class SortedStack {
    priority_queue<int,vi,greater<int>>Q;
public:
    SortedStack() {}
    void push(int val) {
        Q.push(val);
    }
    void pop() {
        if(Q.size())Q.pop();
    }
    int peek() {
        if(Q.empty())return -1;
        return Q.top();
    }
    bool isEmpty() {
        return Q.empty();
    }
};

int main()
{
    cout<<boolalpha;

	SortedStack*obj=new SortedStack();
	obj->push(1);
	obj->push(2);
	obj->peek();
	obj->pop();
	obj->peek();

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