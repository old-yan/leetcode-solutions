#include "utils.h"

int tail[4000]={0},mem[10001],Prev[10001],memcnt,maxlen;
unordered_map<int,int>M;

class FreqStack {
public:
    FreqStack(){
        maxlen=0;
        memcnt=1;
    }
    ~FreqStack(){
        M.clear();
        memset(tail,0,maxlen*sizeof(int));
    }
    void push(int val) {
        auto len=++M[val];
        mem[memcnt]=val;
        Prev[memcnt]=tail[len];
        tail[len]=memcnt++;
        if(len>maxlen)maxlen=len;
    }
    int pop() {
        auto p=tail[maxlen];
        if(!(tail[maxlen]=Prev[p]))maxlen--;
        if(!--M[mem[p]])M.erase(mem[p]);
        return mem[p];
    }
};

int main()
{
    cout<<boolalpha;

	FreqStack*obj=new FreqStack();
	obj->push(4);
	obj->push(0);
	obj->push(9);
	obj->push(3);
	obj->push(4);
	obj->push(2);
	obj->pop();
	obj->push(6);
	obj->pop();
	obj->push(1);
	obj->pop();
	obj->push(1);
	obj->pop();
	obj->push(4);
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