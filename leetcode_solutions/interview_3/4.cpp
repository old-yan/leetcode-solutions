#include "utils.h"

class MyQueue {
    stack<int>in,out;
public:
    MyQueue() {}
    void push(int x) {
        in.push(x);
    }
    int pop() {
        if(out.empty()){
            while(in.size()){
                out.push(in.top());
                in.pop();
            }
        }
        int res=out.top();
        out.pop();
        return res;
    }
    int peek() {
        if(out.empty()){
            while(in.size()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    bool empty() {
        return in.empty()&&out.empty();
    }
};

int main()
{
    cout<<boolalpha;

	MyQueue*obj=new MyQueue();
	obj->push(1);
	obj->push(2);
	obj->peek();
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