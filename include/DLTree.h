#include <iostream>
#include <memory.h>
#include <functional>
using namespace std;

//动态开点+懒惰标记线段树
//需要根据题意，输入op参数，灵活修改inherite函数
template<class T,int cover=0,int bsize=0>
struct DLTree{
    function<T(T&,T&)>op;
    #define DLTREESIZE 4000000
    void inherite(int idx,T _inc){
        val[idx]=cover?(bsize?_inc*sz[idx]:_inc):(bsize?val[idx]+_inc*sz[idx]:val[idx]+_inc);
        inc[idx]=cover?_inc:inc[idx]+_inc;
        lazy[idx]=true;
    }
    T val[DLTREESIZE]={0},inc[DLTREESIZE]={0},lc[DLTREESIZE]={0},rc[DLTREESIZE]={0},p[DLTREESIZE]={0},sz[DLTREESIZE]={0},X,Y,cnt,default_val,default_inc;
    bool lazy[DLTREESIZE]={0};
    DLTree(int range,T _default_val,T _default_inc,function<T(T&,T&)>_op):cnt(1),default_val(_default_val),default_inc(_default_inc),op(_op){
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
            memset(a,0,(cnt+1)*sizeof(T));
        }
        memset(lazy,0,(cnt+1)*sizeof(bool));
        cnt=1;sz[1]=X;
    }
    inline int Lc(int cur){
        if(!lc[cur]){
            lc[cur]=++cnt;
            p[cnt]=cur;
            if constexpr(bsize)sz[cnt]=sz[cur]>>1;
        }
        return lc[cur];
    }
    inline int Rc(int cur){
        if(!rc[cur]){
            rc[cur]=++cnt;
            p[cnt]=cur;
            if constexpr(bsize)sz[cnt]=sz[cur]>>1;
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
    void step(int idx,T value){
        auto a=push_down(idx);
        inherite(a,value);
        for(;p[a];a=p[a])push_up(p[a]);
    }
    void step(int l,int r,T value){
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
    T operator[](int idx){
        return val[push_down(idx)];
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        auto a=push_down(l),b=push_down(r);
        T res=op(val[a],val[b]);
        for(;p[a]!=p[b];a=p[a],b=p[b]){
            if(a==lc[p[a]])res=op(res,val[Rc(p[a])]);
            if(b==rc[p[b]])res=op(res,val[Lc(p[b])]);
        }
        return res;
    }
};