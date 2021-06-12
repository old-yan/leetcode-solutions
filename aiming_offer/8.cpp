#include "utils.h"

class CQueue {
    stack<int>in,out;
public:
    CQueue() {}
    void appendTail(int value) {
        in.push(value);
    }
    int deleteHead() {
        if(out.empty()){
            while(in.size()){
                out.push(in.top());
                in.pop();
            }
        }
        if(out.empty())return -1;
        int res=out.top();
        out.pop();
        return res;
    }
};

int main()
{
    cout<<boolalpha;

	CQueue*obj=new CQueue();
	obj->appendTail(3);
	obj->deleteHead();
	obj->deleteHead();
	obj->deleteHead();

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