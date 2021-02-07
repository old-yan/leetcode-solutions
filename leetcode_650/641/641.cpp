#include "utils.h"

class MyCircularDeque {
    struct node{
        int val;
        node*prev,*next;
        node():val(-1),prev(nullptr),next(nullptr){}
        node(int _val):val(_val),prev(nullptr),next(nullptr){}
        node(int _val,node*_prev,node*_next):val(_val),prev(_prev),next(_next){}
    };
    node*head,*tail;
    int size,curnum;
    void insert(node*next,node*p){
        p->next=next;
        p->prev=next->prev;
        next->prev->next=p;
        next->prev=p;
    }
    void erase(node*p){
        p->next->prev=p->prev;
        p->prev->next=p->next;
        delete p;
    }
public:
    MyCircularDeque(int k):head(new node),tail(new node),size(k),curnum(0){
        head->next=tail;
        tail->prev=head;
    }
    bool insertFront(int value) {
        if(curnum==size)return false;
        insert(head->next,new node(value));
        curnum++;
        return true;
    }
    bool insertLast(int value) {
        if(curnum==size)return false;
        insert(tail,new node(value));
        curnum++;
        return true;
    }
    bool deleteFront() {
        if(!curnum)return false;
        erase(head->next);
        curnum--;
        return true;
    }
    bool deleteLast() {
        if(!curnum)return false;
        erase(tail->prev);
        curnum--;
        return true;
    }
    int getFront() {
        return head->next->val;
    }
    int getRear() {
        return tail->prev->val;
    }
    bool isEmpty() {
        return !curnum;
    }
    bool isFull() {
        return curnum==size;
    }
};

int main()
{
    cout<<boolalpha;

	MyCircularDeque*obj=new MyCircularDeque(3);
	obj->insertLast(1);
	obj->insertLast(2);
	obj->insertFront(3);
	obj->insertFront(4);
	obj->getRear();
	obj->isFull();
	obj->deleteLast();
	obj->insertFront(4);
	obj->getFront();

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