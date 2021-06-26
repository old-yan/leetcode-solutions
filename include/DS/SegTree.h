#pragma once
#include <iostream>
using namespace std;
#define OLDYAN_SEGTREE

//线段树
#define SEGTREEDEPTH 17
template<class T,T ini,class Accumulate>
class SegTree{
    T data[1<<(SEGTREEDEPTH+1)],default_val=ini;
    int X;
    Accumulate op;
    void update(int i){
        data[i]=op(data[i*2],data[i*2+1]);
    }
public:
    SegTree(int n,Accumulate _op):op(_op){
        X=1<<(32-__builtin_clz(n-1));
        for(int i=0;i<X;i++)data[X+i]=ini;
        for(int i=X-1;i;i--)update(i);
    }
    template<class iterator>SegTree(iterator begin,iterator end,Accumulate _op):op(_op){
        int n=end-begin;
        X=1<<(32-__builtin_clz(n-1));
        for(int i=0;i<n;i++)data[X+i]=*(begin+i);
        fill(data+X+n,data+X*2,ini);
        for(int i=X-1;i;i--)update(i);
    }
    void set(int i,T val){
        if(i<0||i>=X)return;
        data[i+=X]=val;
        while(i>>=1)update(i);
    }
    void step(int i,T inc){
        if(i<0||i>=X)return;
        data[i+X]=op(data[i+X],inc);
        for(i+=X;i>>=1;)update(i);
    }
    T&operator[](int i){
        if(i<0||i>=X)return default_val;
        return data[X+i];
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return data[l+X];
        int cur;l+=X;r+=X;
        T res=data[l];
        for(cur=0;l>>(cur+1)!=r>>(cur+1);cur++)
            if(!(l>>cur&1))res=op(res,data[l>>cur^1]);
        while(--cur>=0)
            if(r>>cur&1)res=op(res,data[r>>cur^1]);
        return op(res,data[r]);
    }
    T all(){
        return data[1];
    }
    int find_nth(T n){
        if(n<0||n>=data[1])return -1;
        int i=1;
        while(i<X)
            if(data[i*2]>=n+1)i<<=1;
            else n-=data[i*2],i=i<<1^1;
        return i-X;
    }
};

//模板懒惰标记线段树
#define LAZYTREEDEPTH 17
template<class T,uint8_t bsize=1,class F=T,class Accumulate=T(*)(T,F),class Mapping=Accumulate,class Composition=Accumulate>
class LazyTree{
    T data[1<<(LAZYTREEDEPTH+1)],default_val;
    F inc[1<<(LAZYTREEDEPTH+1)],default_inc;
    bool lazy[1<<(LAZYTREEDEPTH+1)];
    int X,Y;
    Accumulate op;
    Mapping map;
    Composition com;
    inline int size(int i){
        return 1<<(__builtin_clz(i)+Y-31);
    }
    void inherite(int i,F _inc){
        if constexpr(bsize)data[i]=map(data[i],_inc*size(i));
        else data[i]=map(data[i],_inc);
        inc[i]=com(inc[i],_inc);
        lazy[i]=true;
    }
    void update(int i){
        data[i]=op(data[i<<1],data[i<<1^1]);
    }
    void push_down(int i){
        if(!lazy[i])return;
        inherite(i<<1,inc[i]);
        inherite(i<<1^1,inc[i]);
        inc[i]=default_inc;
        lazy[i]=false;
    }
public:
    LazyTree(int n,Accumulate _op):LazyTree(n,_op,_op,_op){}
    LazyTree(int n,Accumulate _op,Mapping _map,Composition _com,T _val=T(),F _inc=F()):op(_op),map(_map),com(_com),default_val(_val),default_inc(_inc){
        reset(n);
    }
    template<class iterator>LazyTree(iterator begin,iterator end,Accumulate _op):LazyTree(begin,end,_op,_op,_op){}
    template<class iterator>LazyTree(iterator begin,iterator end,Accumulate _op,Mapping _map,Composition _com,T _val=T(),F _inc=F()):op(_op),map(_map),com(_com),default_val(_val),default_inc(_inc){
        reset(begin,end);
    }
    void reset(int n){
        Y=32-__builtin_clz(n-1),X=1<<Y;
        for(int i=0;i<X;i++)data[X+i]=default_val;
        for(int i=X-1;i;i--)update(i);
        fill(inc,inc+X*2,default_inc);
        fill(lazy,lazy+X*2,false);
    }
    template<class iterator>void reset(iterator begin,iterator end){
        int n=end-begin;
        Y=32-__builtin_clz(n-1),X=1<<Y;
        for(int i=0;i<n;i++)data[X+i]=*(begin+i);
        fill(data+X+n,data+X*2,default_val);
        for(int i=X-1;i;i--)update(i);
        fill(inc,inc+X*2,default_inc);
        fill(lazy,lazy+X*2,false);
    }
    void set(int i,T val){
        if(i<0||i>=X)return;
        i+=X;
        for(int d=Y;d;d--)push_down(i>>d);
        data[i]=val;
        while(i>>=1)update(i);
    }
    void step(int i,F _inc){
        if(i<0||i>=X)return;
        i+=X;
        for(int d=Y;d;d--)push_down(i>>d);
        inherite(i,_inc);
        while(i>>=1)update(i);
    }
    void step(int l,int r,F _inc){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return;
        if(l==r)step(l,_inc);
        else{
            l+=X,r+=X;
            for(int d=Y;d;d--){
                push_down(l>>d);
                push_down(r>>d);
            }
            inherite(l,_inc);
            inherite(r,_inc);
            while((l>>1)!=(r>>1)){
                if(!(l&1))inherite(l^1,_inc);
                if(r&1)inherite(r^1,_inc);
                update(l>>=1);
                update(r>>=1);
            }
            while(l>>=1)update(l);
        }
    }
    T&operator[](int i){
        if(i<0||i>=X)return default_val;
        i+=X;
        for(int d=Y;d;d--)push_down(i>>d);
        return data[i];
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        l+=X,r+=X;
        for(int d=Y;d;d--){
            push_down(l>>d);
            push_down(r>>d);
        }
        int cur;T res=data[l];
        for(cur=0;l>>(cur+1)!=r>>(cur+1);cur++)
            if(!(l>>cur&1))res=op(res,data[l>>cur^1]);
        while(--cur>=0)
            if(r>>cur&1)res=op(res,data[r>>cur^1]);
        return op(res,data[r]);
    }
    T all(){
        return data[1];
    }
    int find_nth(T n){
        if(n>=data[1])return -1;
        int i=1;
        while(i<X){
            push_down(i);
            if(data[i<<1]>=n)i<<=1;
            else n-=data[i<<1],i=i<<1^1;
        }
        return i-X;
    }
};
