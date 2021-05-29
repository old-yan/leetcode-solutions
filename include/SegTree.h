#pragma once
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <functional>
#include <type_traits>
using namespace std;
#define OLDYAN_ZKWTREE

//模板线段树
template<class T>
struct SegTree{
    #define SEGTREEDEPTH 8
    typedef function<T(const T&,const T&)> Operation;
    T data[1<<(SEGTREEDEPTH+1)]={0},default_val{0};
    int X;
    Operation op;
    SegTree(int n,Operation _op):op(_op){
        cout<<"attention TREESIZE,<="<<(1<<SEGTREEDEPTH)<<'\n';
        for(X=4;X<n;X<<=1);
    }
    template<class Tlike>
    void set(const vector<Tlike>&nums,T val=0){
        for(int i=0;i<nums.size();i++){
            data[X+i]=nums[i];
        }
        fill(data+X+nums.size(),data+X*2,val);
        for(int i=X-1;i;i--){
            data[i]=op(data[i*2],data[i*2+1]);
        }
        int a=5;
        a++;
    }
    void set(T val){
        fill(data+X,data+X*2,val);
        for(int i=X-1;i>=0;i--){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    void set(int i,T val){
        data[i+=X]=val;
        while(i>>=1){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    T& operator[](int i){
        return data[i+X];
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return data[l+X];
        int cur;l+=X;r+=X;
        T res=data[l];
        for(cur=0;l>>(cur+1)!=r>>(cur+1);cur++){
            if(!(l>>cur&1))res=op(res,data[l>>cur^1]);
        }
        while(--cur>=0){
            if(r>>cur&1)res=op(res,data[r>>cur^1]);
        }
        return op(res,data[r]);
    }
    void step(int i,T inc){
        for(i+=X;i;i>>=1)data[i]=op(data[i],inc);
    }
    void step_forward(T i){
        if(is_same<T,int>::value||is_same<T,long long>::value){
            for(i+=X;i;i>>=1)data[i]++;
        }
    }
    void step_back(T i){
        if(is_same<T,int>::value||is_same<T,long long>::value){
            for(i+=X;i;i>>=1)data[i]--;
        }
    }
    int find_nth(T n){
        if((is_same<T,int>::value||is_same<T,long long>::value)&&n<data[1]){
            int i=1;
            while(i<X){
                if(data[i*2]>=n+1){
                    i<<=1;
                }
                else{
                    n-=data[i*2];
                    i=i*2+1;
                }
            }
            return i-X;
        }
        else return -1;
    }
};

//模板懒惰标记线段树，适用各种区间修改操作
template<class T,int cover=0,int bsize=0>
struct LazyTree{
    #define LAZYTREEDEPTH 8
    typedef function<T(const T&,const T&)> Operation;
    inline int size(int i){
        return 1<<(__builtin_clz(i)+Y-31);
    }
    //重载inherite，描述继承增量时的结点形为
    void inherite(int i,T _inc){
        data[i]=cover?(bsize?_inc*size(i):_inc):(bsize?op(data[i],_inc*size(i)):op(data[i],_inc));
        inc[i]=cover?_inc:op(inc[i],_inc);
        lazy[i]=true;
    }
    T data[1<<(LAZYTREEDEPTH+1)]={0},inc[1<<(LAZYTREEDEPTH+1)]={0},default_val{0},default_inc{0};
    bool lazy[1<<(LAZYTREEDEPTH+1)]={0};
    int X,Y;
    Operation op;
    LazyTree(int n,Operation _op):op(_op){
        cout<<"attention TREESIZE,<="<<(1<<LAZYTREEDEPTH)<<'\n';
        for(X=4,Y=2;X<n;X<<=1,Y++);
    }
    template<class Tlike>
    void set(const vector<Tlike>&nums,T val=0){
        for(int i=0;i<nums.size();i++){
            data[X+i]=nums[i];
        }
        fill(data+X+nums.size(),data+X*2,val);
        for(int i=X-1;i;i--){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    void set(T val){
        fill(data+X,data+X*2,val);
        for(int i=X-1;i;i--){
            data[i]=op(data[i*2],data[i*2+1]);
        }
        fill(inc,inc+X*2,default_inc);
        fill(lazy,lazy+X*2,false);
    }
    void setinc(T _inc){
        default_inc=_inc;
        fill(inc,inc+X*2,_inc);
    }
    void set(int i,T val){
        push_down(i);
        data[i+=X]=val;
        while(i>>=1){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    void step(int i,T _inc){
        push_down(i);
        inherite(i+=X,_inc);
        while(i>>=1){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    void step(int l,int r,T _inc){
        if(l==r)step(l,_inc);
        else if(l<r){
            push_down(l);
            push_down(r);
            inherite(l+=X,_inc);
            inherite(r+=X,_inc);
            while((l>>1)!=(r>>1)){
                if(l%2==0)inherite(l+1,_inc);
                if(r%2)inherite(r-1,_inc);
                data[l>>1]=op(data[l],data[l^1]);
                data[r>>1]=op(data[r],data[r^1]);
                l>>=1;
                r>>=1;
            }
            while(l>>=1){
                data[l]=op(data[l*2],data[l*2+1]);
            }
        }
    }
    void push_down(int i){
        for(int j=Y,k=1;j;k=(i&(1<<--j))?(k<<1)+1:k<<1){
            if(lazy[k]){
                inherite(k*2,inc[k]);
                inherite(k*2+1,inc[k]);
                inc[k]=default_inc;
                lazy[k]=false;
            }
        }
    }
    T& operator[](int i){
        push_down(i);
        return data[i+X];
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        push_down(l);
        push_down(r);
        int cur;l+=X;r+=X;
        T res=data[l];
        for(cur=0;l>>(cur+1)!=r>>(cur+1);cur++){
            if(!(l>>cur&1))res=op(res,data[l>>cur^1]);
        }
        while(--cur>=0){
            if(r>>cur&1)res=op(res,data[r>>cur^1]);
        }
        return op(res,data[r]);
    }
    int find_nth(T n){
        if(n<data[1]){
            int i=1;
            while(i<X){
                if(lazy[i]){
                    inherite(i*2,inc[i]);
                    inherite(i*2+1,inc[i]);
                    inc[i]=default_inc;
                    lazy[i]=false;
                }
                if(data[i*2]>=n+1){
                    i<<=1;
                }
                else{
                    n-=data[i*2];
                    i=(i<<1)+1;
                }
            }
            return i-X;
        }
        else return -1;
    }
};

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