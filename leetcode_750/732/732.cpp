//#include "DLTree.h"
#include "utils.h"

class DLTree{
    function<int(int&,int&)>op;
    #define DLTREESIZE 100000
    void inherite(int idx,int _inc){
        val[idx]+=_inc;
        inc[idx]+=_inc;
        lazy[idx]=true;
    }
public:
    int val[DLTREESIZE]={0},inc[DLTREESIZE]={0},lc[DLTREESIZE]={0},rc[DLTREESIZE]={0},p[DLTREESIZE]={0},sz[DLTREESIZE]={0},X,Y,cnt;
    bool lazy[DLTREESIZE]={0};
    DLTree(int range,function<int(int&,int&)>_op):cnt(1),op(_op){
        for(X=4,Y=2;X<=range;X<<=1,Y++);
        sz[1]=X;
    }
    void clear(){
        for(auto a:{val,inc,lc,rc,p,sz}){
            memset(a,0,(cnt+1)*sizeof(int));
        }
        memset(lazy,0,(cnt+1)*sizeof(bool));
        cnt=1;
    }
    inline int Lc(int cur){
        if(!lc[cur]){
            lc[cur]=++cnt;
            p[cnt]=cur;
            sz[cnt]=sz[cur]>>1;
        }
        return lc[cur];
    }
    inline int Rc(int cur){
        if(!rc[cur]){
            rc[cur]=++cnt;
            p[cnt]=cur;
            sz[cnt]=sz[cur]>>1;
        }
        return rc[cur];
    }
    int push_down(int i){
        int cur=1;
        for(int j=Y;j--;cur=i>>j&1?Rc(cur):Lc(cur)){
            if(lazy[cur]){
                inherite(Lc(cur),inc[cur]);
                inherite(Rc(cur),inc[cur]);
                lazy[cur]=false;inc[cur]=0;
            }
        }
        return cur;
    }
    void push_up(int i){
        val[i]=op(val[Lc(i)],val[Rc(i)]);
    }
    void step(int idx,int value){
        auto a=push_down(idx);
        inherite(a,value);
        for(;p[a];a=p[a])push_up(p[a]);
    }
    void step(int l,int r,int value){
        if(l==r)step(l,value);
        else{
            auto a=push_down(l),b=push_down(r);
            inherite(a,value);
            inherite(b,value);
            for(;p[a]!=p[b];a=p[a],b=p[b]){
                if(a==lc[p[a]])inherite(Rc(p[a]),value);
                if(b==rc[p[b]])inherite(Lc(p[b]),value);
                push_up(p[a]);
                push_up(p[b]);
            }
            for(;p[a];a=p[a])push_up(p[a]);
        }
    }
    int operator[](int idx){
        return val[push_down(idx)];
    }
    int operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return 0;
        if(l==r)return (*this)[l];
        auto a=push_down(l),b=push_down(r);
        int res=op(val[a],val[b]);
        for(;p[a]!=p[b];a=p[a],b=p[b]){
            if(a==lc[p[a]])res=op(res,val[Rc(p[a])]);
            if(b==rc[p[b]])res=op(res,val[Lc(p[b])]);
        }
        return res;
    }
};

class MyCalendarThree {
    DLTree T;
public:
    MyCalendarThree():T(1000000000,[](int x,int y){return x>y?x:y;}) {}
    int book(int start, int end) {
        T.step(start,end-1,1);
        return T.val[1];
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