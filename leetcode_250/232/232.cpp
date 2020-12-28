#include "utils.h"

class MyQueue {
    stack<int>S1,S2;
public:
    MyQueue() {}
    void push(int x) {
        S1.push(x);
    }
    int pop() {
        if(!S2.size()){
            while(S1.size()){
                S2.push(S1.top());
                S1.pop();
            }
        }
        int ans=S2.top();
        S2.pop();
        return ans;
    }
    int peek() {
        if(!S2.size()){
            while(S1.size()){
                S2.push(S1.top());
                S1.pop();
            }
        }
        return S2.top();
    }
    bool empty() {
        return S1.empty()&&S2.empty();
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