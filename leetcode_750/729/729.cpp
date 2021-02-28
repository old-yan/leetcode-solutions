#include "utils.h"

class node{
public:
    int count;
    bool b;
    node*lchild,*rchild,*parent;
    node(){};
    node(int _count,bool _b,node*_parent):count(_count),b(_b),lchild(nullptr),rchild(nullptr),parent(_parent){}
    node*getlchild();
    node*getrchild();
};
node mem[500000];
size_t memcnt;

node* node::getlchild(){
    if(!lchild){
        mem[memcnt]=node(0,false,this);
        lchild=mem+memcnt++;
    }
    return lchild;
}
node* node::getrchild(){
    if(!rchild){
        mem[memcnt]=node(0,false,this);
        rchild=mem+memcnt++;
    }
    return rchild;
}

struct Tree{
    const int X=1<<30,Y=30;
    node*root;
    Tree():root(new node(0,false,nullptr)){memcnt=0;}
    void inherite(node*p,int val){
        p->count=val;
        p->b=true;
    }
    void push_up(node*p){
        p->count=p->getlchild()->count+p->getrchild()->count;
    }
    node* push_down(int i){
        auto p=root;
        for(int j=Y;j;){
            if(p->b){
                inherite(p->getlchild(),p->count>>1);
                inherite(p->getrchild(),p->count>>1);
                p->b=false;
            }
            p=(i&(1<<--j))?p->getrchild():p->getlchild();
        }
        return p;
    }
    void set(int l,int r,int val){
        auto a=push_down(l);
        auto b=push_down(r);
        a->count=b->count=val;
        while(a->parent!=b->parent){
            if(a==a->parent->lchild)inherite(a->parent->getrchild(),val);
            if(b==b->parent->rchild)inherite(b->parent->getlchild(),val);
            push_up(a->parent);
            a=a->parent;
            push_up(b->parent);
            b=b->parent;
            val<<=1;
        }
        while(a->parent){
            push_up(a->parent);
            a=a->parent;
        }
    }
    int operator[](int i){
        auto a=push_down(i);
        return a->count;
    }
    int operator()(int l,int r){
        if(l==r)return (*this)[l];
        auto a=push_down(l);
        auto b=push_down(r);
        int res=a->count+b->count;
        while(a->parent!=b->parent){
            if(a==a->parent->lchild)res+=a->parent->getrchild()->count;
            if(b==b->parent->rchild)res+=b->parent->getlchild()->count;
            a=a->parent;
            b=b->parent;
        }
        return res;
    }
};

class MyCalendar {
    Tree T;
public:
    MyCalendar() {}
    bool book(int start, int end) {
        if(T(start,end-1))return false;
        T.set(start,end-1,1);
    }
};

int main()
{
    cout<<boolalpha;

	MyCalendar*obj=new MyCalendar();
	obj->book(10,20);
	obj->book(15,25);
	obj->book(20,30);

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