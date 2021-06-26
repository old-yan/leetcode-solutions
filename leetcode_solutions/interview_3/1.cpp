#include "utils.h"

class TripleInOne {
    vi v;
    int size;
    int cursor[3]={0};
public:
    TripleInOne(int stackSize) {
        v.resize(stackSize*3);
        size=stackSize;
    }
    void push(int stackNum, int value) {
        if(cursor[stackNum]<size)
            v[stackNum*size+cursor[stackNum]++]=value;
    }
    int pop(int stackNum) {
        if(cursor[stackNum]==0)return -1;
        else return v[stackNum*size+--cursor[stackNum]];
    }
    int peek(int stackNum) {
        if(cursor[stackNum]==0)return -1;
        else return v[stackNum*size+cursor[stackNum]-1];
    }    
    bool isEmpty(int stackNum) {
        return !cursor[stackNum];
    }
};

int main()
{
    cout<<boolalpha;

	TripleInOne*obj=new TripleInOne(1);
	obj->push(0,1);
	obj->push(0,2);
	obj->pop(0);
	obj->pop(0);
	obj->pop(0);
	obj->isEmpty(0);

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