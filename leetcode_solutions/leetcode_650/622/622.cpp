#include "utils.h"

class MyCircularQueue {
    vi data;
    int k;
    int head;
    int tail;
public:
    MyCircularQueue(int _k):data(_k+1),k(_k),head(0),tail(0) {}
    bool enQueue(int value) {
        if((tail+1)%(k+1)==head)return false;
        data[tail]=value;
        tail=(tail+1)%(k+1);
        return true;
    }
    bool deQueue() {
        if(head==tail)return false;
        head=(head+1)%(k+1);
        return true;
    }
    int Front() {
        if(head==tail)return -1;
        else return data[head];
    }
    int Rear() {
        if(head==tail)return -1;
        else return data[(tail+k)%(k+1)];
    }
    bool isEmpty() {
        return head==tail;
    }
    bool isFull() {
        return (tail+1)%(k+1)==head;
    }
};

int main()
{
    cout<<boolalpha;

	MyCircularQueue*obj=new MyCircularQueue(3);
	obj->enQueue(1);
	obj->enQueue(2);
	obj->enQueue(3);
	obj->enQueue(4);
	obj->Rear();
	obj->isFull();
	obj->deQueue();
	obj->enQueue(4);
	obj->Rear();

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