#include "utils.h"

class CustomStack {
    int cur,maxSize,time;
    int data[1000]={0};
    int lazy[1000]={0};
public:
    CustomStack(int _maxSize):maxSize(_maxSize),cur(0),time(0) {}
    void push(int x) {
        if(cur<maxSize)data[cur++]=x;
    }
    int pop() {
        if(!cur)return -1;
        if(cur>=2){
            data[cur-2]+=lazy[cur-1];
            lazy[cur-2]+=lazy[cur-1];
        }
        lazy[cur-1]=0;
        return data[--cur];
    }
    void increment(int k, int val) {
        chmin(k,cur);
        lazy[k-1]+=val;
        data[k-1]+=val;
    }
};

int main()
{
    cout<<boolalpha;

	CustomStack*obj=new CustomStack(3);
	obj->push(1);
	obj->push(2);
	obj->pop();
	obj->push(2);
	obj->push(3);
	obj->push(4);
	obj->increment(5,100);
	obj->increment(2,100);
	obj->pop();
	obj->pop();
	obj->pop();
	obj->pop();

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