#include "utils.h"

class MaxQueue {
    deque<int>Max;
    queue<int>Q;
public:
    MaxQueue() {}
    int max_value() {
        if(Q.empty())return -1;
        else return Max.front();
    }
    void push_back(int value) {
        Q.push(value);
        while(Max.size()&&Max.back()<value)Max.pop_back();
        Max.pb(value);
    }
    int pop_front() {
        if(Q.empty())return -1;
        int res=Q.front();
        Q.pop();
        if(Max.size()&&Max.front()==res)Max.pop_front();
        return res;
    }
};

int main()
{
    cout<<boolalpha;

	MaxQueue*obj=new MaxQueue();
	obj->push_back(1);
	obj->push_back(2);
	obj->max_value();
	obj->pop_front();
	obj->max_value();

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