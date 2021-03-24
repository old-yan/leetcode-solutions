#pragma once
#include <algorithm>
#include <memory.h>
#include <vector>
#include <functional>
#include <type_traits>
using namespace std;
#define OLDYAN_ZKWTREE

//最大值线段树
class zkwMaxTree{
public:
    int*data;
    int X;
    int default_val;
    zkwMaxTree(int n=100005,int _default_val=0){
        for(X=4;X<n;X<<=1);
        data=new int[X*2];
        default_val=_default_val;
        fill(data,data+X*2,default_val);
    }
    zkwMaxTree(vector<int>&nums,int _default_val=0){
        for(X=4;X<nums.size();X<<=1);
        data=new int[X*2];
        default_val=_default_val;
        fill(data,data+X*2,default_val);
        if(nums.size()){
            memcpy(data+X,&nums[0],nums.size()*sizeof(int));
        }
        for(int i=X-1;i;i--){
            data[i]=max(data[i*2],data[i*2+1]);
        }
    }
    void set(int i,int val){
        data[i+=X]=val;
        while((i>>=1)){
            if(data[i]!=max(data[i*2],data[i*2+1])){
                data[i]=max(data[i*2],data[i*2+1]);
            }
            else break;
        }
    }
    int operator[](int i){
        return data[i+X];
    }
    int operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        int res=max(data[l+=X],data[r+=X]);
        if(l!=r){
            while(l/2!=r/2){
                if(l%2==0)res=max(res,data[l+1]);
                if(r%2)res=max(res,data[r-1]);
                l>>=1;
                r>>=1;
            }
        }
        return res;
    }
};

//带懒惰标记的最大值线段树，支持区间赋值
class LazyMaxTree{
    struct elem{
        int val;
        bool b;
        elem():val(0),b(false){}
        elem(int _default_val):val(_default_val),b(false){}
        elem(int _val,bool _b):val(_val),b(_b){}
    };
public:
    elem*data;
    int X,Y;
    int default_val;
    LazyMaxTree(int n=100005,int _default_val=0):default_val(_default_val){
        for(X=4;X<n;X<<=1);
        Y=__builtin_ctz(X);
        data=new elem[X*2];
        fill(data,data+X*2,elem(default_val));
    }
    void push_down(int i){
        for(int j=Y,k=1;j;k=(i&(1<<--j))?(k<<1)+1:k<<1){
            if(data[k].b){
                data[k*2]=data[k*2+1]=data[k];
                data[k].b=false;
            }
        }
    }
    void set(int i,int val){
        push_down(i);
        data[i+=X].val=val;
        while(i>>=1){
            data[i].val=max(data[i*2].val,data[i*2+1].val);
        }
    }
    void set(int l,int r,int val){
        if(l==r)set(l,val);
        else{
            push_down(l);
            push_down(r);
            data[l+=X].val=data[r+=X].val=val;
            while((l>>1)!=(r>>1)){
                if(l%2==0)data[l+1]=elem(val,true);
                if(r%2)data[r-1]=elem(val,true);
                data[l>>1].val=max(data[l].val,data[l^1].val);
                data[r>>1].val=max(data[r].val,data[r^1].val);
                l>>=1;
                r>>=1;
            }
            while(l>>=1){
                data[l].val=max(data[l*2].val,data[l*2+1].val);
            }
        }
    }
    int operator[](int i){
        push_down(i);
        return data[i+X].val;
    }
    int operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        push_down(l);
        push_down(r);
        int res=max(data[l+=X].val,data[r+=X].val);
        while(l/2!=r/2){
            if(l%2==0)res=max(res,data[l+1].val);
            if(r%2)res=max(res,data[r-1].val);
            l>>=1;
            r>>=1;
        }
        return res;
    }
};

//最小值线段树
class zkwMinTree{
public:
    int*data;
    int X;
    int default_val;
    zkwMinTree(int n=100005,int _default_val=INT_MAX){
        for(X=4;X<n;X<<=1);
        data=new int[X*2];
        default_val=_default_val;
        fill(data,data+X*2,default_val);
    }
    zkwMinTree(vector<int>&nums,int _default_val=INT_MAX){
        for(X=4;X<nums.size();X<<=1);
        data=new int[X*2];
        default_val=_default_val;
        fill(data,data+X*2,default_val);
        if(nums.size()){
            memcpy(data+X,&nums[0],nums.size()*sizeof(int));
        }
        for(int i=X-1;i;i--){
            data[i]=min(data[i*2],data[i*2+1]);
        }
    }
    void set(int i,int val){
        data[i+=X]=val;
        while((i>>=1)){
            if(data[i]!=min(data[i*2],data[i*2+1])){
                data[i]=min(data[i*2],data[i*2+1]);
            }
            else break;
        }
    }
    int operator[](int i){
        return data[i+X];
    }
    int operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        int res=min(data[l+=X],data[r+=X]);
        if(l!=r){
            while(l/2!=r/2){
                if(l%2==0)res=min(res,data[l+1]);
                if(r%2)res=min(res,data[r-1]);
                l>>=1;
                r>>=1;
            }
        }
        return res;
    }
};

//带懒惰标记的最小值线段树，支持区间赋值
class LazyMinTree{
    struct elem{
        int val;
        bool b;
        elem():val(0),b(false){}
        elem(int _default_val):val(_default_val),b(false){}
        elem(int _val,bool _b):val(_val),b(_b){}
    };
public:
    elem*data;
    int X,Y;
    int default_val;
    LazyMinTree(int n=100005,int _default_val=0):default_val(_default_val){
        for(X=4;X<n;X<<=1);
        Y=__builtin_ctz(X);
        data=new elem[X*2];
        fill(data,data+X*2,elem(default_val));
    }
    void push_down(int i){
        for(int j=Y,k=1;j;k=(i&(1<<--j))?(k<<1)+1:k<<1){
            if(data[k].b){
                data[k*2]=data[k*2+1]=data[k];
                data[k].b=false;
            }
        }
    }
    void set(int i,int val){
        push_down(i);
        data[i+=X].val=val;
        while(i>>=1){
            data[i].val=min(data[i*2].val,data[i*2+1].val);
        }
    }
    void set(int l,int r,int val){
        if(l==r)set(l,val);
        else{
            push_down(l);
            push_down(r);
            data[l+=X].val=data[r+=X].val=val;
            while((l>>1)!=(r>>1)){
                if(l%2==0)data[l+1]=elem(val,true);
                if(r%2)data[r-1]=elem(val,true);
                data[l>>1].val=min(data[l].val,data[l^1].val);
                data[r>>1].val=min(data[r].val,data[r^1].val);
                l>>=1;
                r>>=1;
            }
            while(l>>=1){
                data[l].val=min(data[l*2].val,data[l*2+1].val);
            }
        }
    }
    int operator[](int i){
        push_down(i);
        return data[i+X].val;
    }
    int operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        push_down(l);
        push_down(r);
        int res=min(data[l+=X].val,data[r+=X].val);
        while(l/2!=r/2){
            if(l%2==0)res=min(res,data[l+1].val);
            if(r%2)res=min(res,data[r-1].val);
            l>>=1;
            r>>=1;
        }
        return res;
    }
};

//区间求和线段树
class zkwTree{
public:
    long*data;
    int X;
    int default_val;
    zkwTree(int n=100005,int _default_val=0):default_val(_default_val){
        for(X=4;X<n;X<<=1);
        data=new long[X*2];
        fill(data+X,data+X*2,_default_val);
        for(int i=X-1;i;i--){
            data[i]=data[i*2]+data[i*2+1];
        }
    }
    zkwTree(vector<int>&nums,int _default_val=0):default_val(_default_val){
        for(X=4;X<nums.size();X<<=1);
        data=new long[X*2];
        memset(data+X,0,X*sizeof(long));
        if(nums.size()){
            for(int i=0;i<nums.size();i++)data[X+i]=nums[i];
        }
        for(int i=X-1;i;i--){
            data[i]=data[i*2]+data[i*2+1];
        }
    }
    void reset(){
        for(int i=X*2,val=default_val;i>1;val<<=1){
            for(int j=i>>1;j--;)data[--i]=val;
        }
    }
    void set(int i,long val){
        int d=val-data[i+=X];
        while(i){
            data[i]+=d;
            i>>=1;
        }
    }
    void step(int i){
        i+=X;
        while(i){
            data[i]++;
            i>>=1;
        }
    }
    long operator[](int i){
        return data[i+X];
    }
    long operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return 0;
        if(l!=r){
            long res=data[l+=X]+data[r+=X];
            while(l/2!=r/2){
                if(l%2==0)res+=data[l+1];
                if(r%2)res+=data[r-1];
                l>>=1;
                r>>=1;
            }
            return res;
        }
        else return data[l+X];
    }
    int find_nth(long n){
        if(n>=data[1])return -1;
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
};

//带懒惰标记的求和线段树，支持区间赋值
class LazyCountTree{
    struct elem{
        int val;
        bool b;
        elem():val(0),b(false){}
        elem(int _default_val):val(_default_val),b(false){}
        elem(int _val,bool _b):val(_val),b(_b){}
    };
public:
    elem*data;
    int X,Y;
    int default_val;
    LazyCountTree(int n=100005,int _default_val=0):default_val(_default_val){
        for(X=4;X<n;X<<=1);
        Y=__builtin_ctz(X);
        data=new elem[X*2];
        for(int i=X*2,val=default_val;i>1;val<<=1){
            for(int j=i>>1;j--;)data[--i]=val;
        }
    }
    LazyCountTree(vector<int>&nums,int _default_val=0):default_val(_default_val){
        for(X=4;X<nums.size();X<<=1);
        Y=__builtin_ctz(X);
        data=new elem[X*2];
        for(int i=0;i<X;i++){
            data[X+i]=elem(i<nums.size()?nums[i]:default_val);
        }
        for(int i=X-1;i;){
            data[i]=elem(data[i*2].val+data[i*2+1].val);
        }
    }
    void push_down(int i){
        for(int j=Y,k=1;j;k=(i&(1<<--j))?(k<<1)+1:k<<1){
            if(data[k].b){
                data[k*2]=data[k*2+1]=elem(data[k].val/2,true);
                data[k].b=false;
            }
        }
    }
    void set(int i,int val){
        push_down(i);
        data[i+=X].val=val;
        while(i>>=1){
            data[i].val=data[i*2].val+data[i*2+1].val;
        }
    }
    void set(int l,int r,int val){
        if(l==r)set(l,val);
        else{
            push_down(l);
            push_down(r);
            data[l+=X].val=data[r+=X].val=val;
            while((l>>1)!=(r>>1)){
                if(l%2==0)data[l+1]=elem(val,true);
                if(r%2)data[r-1]=elem(val,true);
                data[l>>1].val=data[l].val+data[l^1].val;
                data[r>>1].val=data[r].val+data[r^1].val;
                l>>=1;
                r>>=1;
                val<<=1;
            }
            while(l>>=1){
                data[l].val=data[l*2].val+data[l*2+1].val;
            }
        }
    }
    int operator[](int i){
        push_down(i);
        return data[i+X].val;
    }
    int operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        push_down(l);
        push_down(r);
        int res=data[l+=X].val+data[r+=X].val;
        while(l/2!=r/2){
            if(l%2==0)res+=data[l+1].val;
            if(r%2)res+=data[r-1].val;
            l>>=1;
            r>>=1;
        }
        return res;
    }
};

//模板线段树
template<class T>
class SegTree{
    #define SEGTREEDEPTH 17
    typedef function<T(T&,T&)> Operation;
public:
    T data[1<<(SEGTREEDEPTH+1)]={0};
    int X;
    T default_val;
    Operation op;
    SegTree(int n,T _default_val,Operation _op):default_val(_default_val),op(_op){
        for(X=4;X<n;X<<=1);
        if(memcmp(data,&default_val,sizeof(default_val))){
            fill(data+X,data+X*2,default_val);
        }
        for(int i=X-1;i;i--){
            data[i]=op(data[i*2],data[i*2+1]);
        }
    }
    template<class Tlike>
    SegTree(vector<Tlike>&nums,T _default_val,Operation _op):default_val(_default_val),op(_op){
        for(X=4;X<nums.size();X<<=1);
        for(int i=0;i<nums.size();i++){
            data[X+i]=nums[i];
        }
        if(memcmp(data,&default_val,sizeof(default_val))){
            fill(data+X+nums.size(),data+X*2,default_val);
        }
        for(int i=X-1;i;i--){
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
        T res=op(data[l+=X],data[r+=X]);
        while(l/2!=r/2){
            if(l%2==0)res=op(res,data[l+1]);
            if(r%2)res=op(res,data[r-1]);
            l>>=1;
            r>>=1;
        }
        return res;
    }
    void step(int i,T inc){
        for(i+=X;i;i>>=1)data[i]=op(data[i],inc);
    }
    void step_forward(T i){
        if(is_same<T,int>::value||is_same<T,long>::value){
            for(i+=X;i;i>>=1)data[i]++;
        }
    }
    void step_back(T i){
        if(is_same<T,int>::value||is_same<T,long>::value){
            for(i+=X;i;i>>=1)data[i]--;
        }
    }
    int find_nth(T n){
        if((is_same<T,int>::value||is_same<T,long>::value)&&n<data[1]){
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
template<class T>
class LazyTree{
    #define LAZYTREEDEPTH 17
    typedef function<T(T&,T&)> Operation;
    struct elem{
        T val;
        T inc;
        bool b;
        elem():val(),inc(),b(false){}
        elem(T _val):val(_val),inc(),b(false){}
        elem(T _val,T _inc):val(_val),inc(_inc),b(false){}
        elem(T _val,T _inc,bool _b):val(_val),inc(_inc),b(_b){}
    };
    inline int size(int i){
        return __builtin_clz(i)+Y-31;
    }
    //重载inherite，描述继承增量时的结点形为
    void inherite(int i,T inc){
        data[i].val+=inc;
        data[i].inc+=inc;
        data[i].b=true;
    }
public:
    elem data[1<<(LAZYTREEDEPTH+1)];
    int X,Y;
    T default_val;
    Operation op;
    LazyTree(int n,T _default_val,Operation _op):default_val(_default_val),op(_op){
        for(X=4;X<n;X<<=1);
        Y=__builtin_ctz(X);
        if(memcmp(data,&default_val,sizeof(default_val))){
            fill(data+X,data+X*2,elem(default_val));
        }
        for(int i=X-1;i;i--){
            data[i].val=op(data[i*2].val,data[i*2+1].val);
        }
    }
    template<class Tlike>
    LazyTree(vector<Tlike>&nums,T _default_val,Operation _op):default_val(_default_val),op(_op){
        for(X=4;X<nums.size();X<<=1);
        Y=__builtin_ctz(X);
        for(int i=0;i<nums.size();i++){
            data[X+i]=nums[i];
        }
        if(memcmp(data,&default_val,sizeof(default_val))){
            fill(data+X+nums.size(),data+X*2,default_val);
        }
        for(int i=X-1;i;i--){
            data[i]=elem(op(data[i*2].val,data[i*2+1].val));
        }
    }
    void set(int i,T val){
        push_down(i);
        data[i+=X].val=val;
        while(i>>=1){
            data[i].val=op(data[i*2].val,data[i*2+1].val);
        }
    }
    void step(int i,T inc){
        push_down(i);
        inherite(i+=X,inc);
        while(i>>=1){
            data[i].val=op(data[i*2].val,data[i*2+1].val);
        }
    }
    void step(int l,int r,T inc){
        if(l==r)step(l,inc);
        else{
            push_down(l);
            push_down(r);
            inherite(l+=X,inc);
            inherite(r+=X,inc);
            while((l>>1)!=(r>>1)){
                if(l%2==0)inherite(l+1,inc);
                if(r%2)inherite(r-1,inc);
                data[l>>1].val=op(data[l].val,data[l^1].val);
                data[r>>1].val=op(data[r].val,data[r^1].val);
                l>>=1;
                r>>=1;
            }
            while(l>>=1){
                data[l].val=op(data[l*2].val,data[l*2+1].val);
            }
        }
    }
    void push_down(int i){
        for(int j=Y,k=1;j;k=(i&(1<<--j))?(k<<1)+1:k<<1){
            if(data[k].b){
                inherite(k*2,data[k].inc);
                inherite(k*2+1,data[k].inc);
                data[k]=elem(data[k].val);
            }
        }
    }
    T& operator[](int i){
        push_down(i);
        return data[i+X].val;
    }
    T operator()(int l,int r){
        l=max(l,0);
        r=min(r,X-1);
        if(l>r)return default_val;
        if(l==r)return (*this)[l];
        push_down(l);
        push_down(r);
        T res=op(data[l+=X].val,data[r+=X].val);
        while(l/2!=r/2){
            if(l%2==0)res=op(res,data[l+1].val);
            if(r%2)res=op(res,data[r-1].val);
            l>>=1;
            r>>=1;
        }
        return res;
    }
    int find_nth(T n){
        if(n<data[1]){
            int i=1;
            while(i<X){
                if(data[i].b){
                    data[i*2].inherite(data[i].inc/2);
                    data[i*2+1].inherite(data[i].inc/2);
                    data[i]=elem(data[i].val);
                }
                if(data[i*2].val>=n+1){
                    i<<=1;
                }
                else{
                    n-=data[i*2].val;
                    i=(i<<1)+1;
                }
            }
            return i-X;
        }
        else return -1;
    }
};