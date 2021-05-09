//#include "DLTree.h"
#include "utils.h"

struct DLTree{
    function<int(int&,int&)>op;
    #define DLTREESIZE 450000
    void inherite(int idx,int _inc){
        val[idx]=sz[idx]*_inc;
        inc[idx]=_inc;
        lazy[idx]=true;
    }
    int val[DLTREESIZE]={0},inc[DLTREESIZE]={0},lc[DLTREESIZE]={0},rc[DLTREESIZE]={0},p[DLTREESIZE]={0},sz[DLTREESIZE]={0},X,Y,cnt,default_val,default_inc;
    bool lazy[DLTREESIZE]={0};
    DLTree(int range,int _default_val,int _default_inc,function<int(int&,int&)>_op):cnt(1),default_val(_default_val),default_inc(_default_inc),op(_op){
        cout<<"attention TREESIZE,<="<<DLTREESIZE<<'\n';
        for(X=4,Y=2;X<=range;X<<=1,Y++);
        if(default_val)fill(val,val+DLTREESIZE,default_val);
        if(default_inc)fill(inc,inc+DLTREESIZE,default_inc);
        sz[1]=X;
    }
    void clear(){
        fill(val,val+cnt+1,default_val);
        fill(inc,inc+cnt+1,default_inc);
        for(auto a:{lc,rc,p,sz}){
            memset(a,0,(cnt+1)*sizeof(int));
        }
        memset(lazy,0,(cnt+1)*sizeof(bool));
        cnt=1;sz[1]=X;
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
                lazy[cur]=false;inc[cur]=default_inc;
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
        if(l>r)return default_val;
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

DLTree T(1000000000,0,0,[](int x,int y){return x+y;});
class RangeModule {
public:
    RangeModule() {
        T.clear();
    }
    void addRange(int left, int right) {
        T.step(left,right-1,1);
    }
    bool queryRange(int left, int right) {
        return T(left,right-1)==right-left;
    }
    void removeRange(int left, int right) {
        T.step(left,right-1,0);
    }
};

int main()
{
    cout<<boolalpha;

	RangeModule*obj=new RangeModule();
	obj->addRange(10,20);
	obj->removeRange(14,16);
	DBG(obj->queryRange(10,14));
	DBG(obj->queryRange(13,15));
	DBG(obj->queryRange(16,17));

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