#include "ListNode.h"
#include "utils.h"

//bitset或者bool数组是最简单的做法，但是遇到数字范围较大的情况就无法处理了
ListNode mem[20000];
size_t memcnt;

class MyHashSet {
    #define X 4999
    ListNode*bucket[X]={0};
public:
    MyHashSet() {
        memset(mem,0,sizeof(mem));
        for(int i=0;i<X;i++)bucket[i]=mem+i;
        memcnt=X;
    }
    void add(int key) {
        ListNode*p=bucket[key%X];
        while(p->next&&p->next->val<=key){
            if(p->next->val==key)return;
            p=p->next;
        }
        mem[memcnt]=ListNode(key,p->next);
        p->next=mem+memcnt++;
    }
    void remove(int key) {
        ListNode*p=bucket[key%X];
        while(p->next&&p->next->val<=key){
            if(p->next->val==key){
                p->next=p->next->next;
                return;
            }
            p=p->next;
        }
    }
    bool contains(int key) {
        ListNode*p=bucket[key%X];
        while(p->next&&p->next->val<=key){
            if(p->next->val==key)return true;
            p=p->next;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;

	MyHashSet*obj=new MyHashSet();
	obj->add(1);
	obj->add(2);
	obj->contains(1);
	obj->contains(3);
	obj->add(2);
	obj->contains(2);
	obj->remove(2);
	obj->contains(2);

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