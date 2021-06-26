#include "utils.h"

class MyStack {
    queue<int>Q;
public:
    MyStack() {}
    void push(int x) {
        queue<int>Q2;
        Q2.push(x);
        while(Q.size()){
            Q2.push(Q.front());
            Q.pop();
        }
        swap(Q,Q2);
    }
    int pop() {
        int ans=Q.front();
        Q.pop();
        return ans;
    }
    int top() {
        return Q.front();
    }
    bool empty() {
        return Q.empty();
    }
};

int main()
{
    cout<<boolalpha;

    MyStack*obj=new MyStack();
	obj->push(1);
	obj->push(2);
	obj->top();
	obj->pop();
	obj->empty();

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