#include "DuLinkList.h"
#include "utils.h"

DuLinkList mem[1000];
size_t memcnt;

class MyLinkedList {
    DuLinkList*head,*tail;
    int len;
    static DuLinkList abcd[1000];
    void insert(DuLinkList*prev,DuLinkList*next,int val){
        mem[memcnt]=DuLinkList(val,prev,next);
        prev->next=next->prev=mem+memcnt++;
        len++;
    }
    void del(DuLinkList*cur){
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
        len--;
    }
    DuLinkList*findnode(int index){
        DuLinkList*p;
        if(index<len/2){
            for(p=head;index-->=0;p=p->next);
        }
        else{
            index=len-index;
            for(p=tail;index--;p=p->prev);
        }
        return p;
    }
public:
    MyLinkedList():head(new DuLinkList),tail(new DuLinkList),len(0){
        head->next=tail;
        tail->prev=head;
        memcnt=0;
    }
    int get(int index) {
        if(index<0||index>=len)return -1;
        return findnode(index)->val;
    }
    void addAtHead(int val) {
        insert(head,head->next,val);
    }
    void addAtTail(int val) {
        insert(tail->prev,tail,val);
    }
    void addAtIndex(int index, int val) {
        if(index<=0)addAtHead(val);
        else if(index>=len)addAtTail(val);
        else{
            DuLinkList*p=findnode(index);
            insert(p->prev,p,val);
        }
    }
    void deleteAtIndex(int index) {
        if(index<0||index>=len)return;
        del(findnode(index));
    }
};

int main()
{
    cout<<boolalpha;

	MyLinkedList*obj=new MyLinkedList();
	obj->addAtHead(1);
	obj->addAtTail(3);
	obj->addAtIndex(1,2);
	DBG(obj->get(1));
	obj->deleteAtIndex(1);
	DBG(obj->get(1));

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