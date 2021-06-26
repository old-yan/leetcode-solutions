#include "utils.h"

struct node{
    int key,value;
    node*next;
    node(){}
    node(int _key,int _value,node*_next):key(_key),value(_value),next(_next){}
};

node mem[20000];
size_t memcnt;

class MyHashMap {
    #define X 4999
    node*bucket[X]={0};
public:
    MyHashMap() {
        memset(mem,0,sizeof(mem));
        for(int i=0;i<X;i++)bucket[i]=mem+i;
        memcnt=X;
    }
    void put(int key, int value) {
        auto*p=bucket[key%X];
        while(p->next&&p->next->key<=key){
            if(p->next->key==key){
                p->next->value=value;
                return;
            }
            p=p->next;
        }
        mem[memcnt]=node(key,value,p->next);
        p->next=mem+memcnt++;
    }
    int get(int key) {
        auto*p=bucket[key%X];
        while(p->next&&p->next->key<=key){
            if(p->next->key==key){
                return p->next->value;
            }
            p=p->next;
        }
        return -1;
    }
    void remove(int key) {
        auto*p=bucket[key%X];
        while(p->next&&p->next->key<=key){
            if(p->next->key==key){
                p->next=p->next->next;
                return;
            }
            p=p->next;
        }
    }
};

int main()
{
    cout<<boolalpha;

	MyHashMap*obj=new MyHashMap();
	obj->put(1,1);
	obj->put(2,2);
	obj->get(1);
	obj->get(3);
	obj->put(2,1);
	obj->get(2);
	obj->remove(2);
	obj->get(2);

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