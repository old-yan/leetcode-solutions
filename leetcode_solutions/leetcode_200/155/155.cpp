#include "utils.h"

class MinStack {
    multiset<int>data;
    stack<int>S;
public:
    MinStack() {}
    void push(int x) {
        data.insert(x);
        S.push(x);
    }
    void pop() {
        data.erase(data.find(S.top()));
        S.pop();
    }
    int top() {
        DBG(S.top());
        return S.top();
    }
    int getMin() {
        DBG(*data.begin());
        return *data.begin();
    }
};

int main()
{
    cout<<boolalpha;

    MinStack*obj=new MinStack();
    obj->push(-2);
	obj->push(0);
	obj->push(-3);
	obj->getMin();
	obj->pop();
	obj->top();
	obj->getMin();

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