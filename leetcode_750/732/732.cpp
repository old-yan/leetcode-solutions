#include "utils.h"

class node{
public:
    int Max,cnt;
    bool b;
    node*lchild,*rchild,*parent;
    node(){};
    node(int _Max,int _cnt,bool _b,node*_parent):Max(_Max),cnt(_cnt),b(_b),lchild(nullptr),rchild(nullptr),parent(_parent){}
    node*getlchild();
    node*getrchild();
};
node mem[100000];
size_t memcnt;

node* node::getlchild(){
    if(!lchild){
        mem[memcnt]=node(0,0,false,this);
        lchild=mem+memcnt++;
    }
    return lchild;
}
node* node::getrchild(){
    if(!rchild){
        mem[memcnt]=node(0,0,false,this);
        rchild=mem+memcnt++;
    }
    return rchild;
}

struct Tree{
    const int X=1<<30,Y=30;
    node*root;
    Tree():root(new node(0,0,false,nullptr)){memcnt=0;}
    void inherite(node*p,int val){
        p->Max+=val;
        p->cnt+=val;
        p->b=true;
    }
    void push_up(node*p){
        p->Max=max(p->getlchild()->Max,p->getrchild()->Max);
    }
    node* push_down(int i){
        auto p=root;
        for(int j=Y;j;){
            if(p->b){
                inherite(p->getlchild(),p->cnt);
                inherite(p->getrchild(),p->cnt);
                p->cnt=0;
                p->b=false;
            }
            p=(i&(1<<--j))?p->getrchild():p->getlchild();
        }
        return p;
    }
    void step(int l,int r,int val){
        auto a=push_down(l);
        auto b=push_down(r);
        a->Max+=val;
        if(b!=a)b->Max+=val;
        while(a->parent!=b->parent){
            if(a==a->parent->lchild)inherite(a->parent->getrchild(),val);
            if(b==b->parent->rchild)inherite(b->parent->getlchild(),val);
            push_up(a->parent);
            a=a->parent;
            push_up(b->parent);
            b=b->parent;
        }
        while(a->parent){
            push_up(a->parent);
            a=a->parent;
        }
    }
    int operator[](int i){
        auto a=push_down(i);
        return a->Max;
    }
    int operator()(int l,int r){
        if(l==r)return (*this)[l];
        auto a=push_down(l);
        auto b=push_down(r);
        int res=max(a->Max,b->Max);
        while(a->parent!=b->parent){
            if(a==a->parent->lchild)res=max(res,a->parent->getrchild()->Max);
            if(b==b->parent->rchild)res=max(res,b->parent->getlchild()->Max);
            a=a->parent;
            b=b->parent;
        }
        return res;
    }
};

class MyCalendarThree {
    Tree T;
public:
    MyCalendarThree() {}
    int book(int start, int end) {
        T.step(start,end-1,1);
        return T.root->Max;
    }
};

int main()
{
    cout<<boolalpha;

	MyCalendarThree*obj=new MyCalendarThree();
	obj->book(10,20);
	obj->book(50,60);
	obj->book(10,40);
	obj->book(5,15);
	obj->book(5,10);
	obj->book(25,55);

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