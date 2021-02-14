#pragma once
#include <algorithm>
#include <memory.h>
#include <vector>
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

//区间求和线段树
class zkwTree{
public:
    long*data;
    int X;
    zkwTree(int n=100005,int _default_val=0){
        for(X=4;X<n;X<<=1);
        data=new long[X*2];
        memset(data+X,0,X*sizeof(long));
        fill(data+X,data+X*2,_default_val);
        for(int i=X-1;i;i--){
            data[i]=data[i*2]+data[i*2+1];
        }
    }
    zkwTree(vector<int>&nums){
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

//模板线段树
template<class T>
class Tree{
    typedef T (*Operation)(T&x,T&y);
public:
    T*data;
    int X;
    T default_val;
    Operation op;
    Tree(int n,T _default_val,Operation _op):default_val(_default_val),op(_op){
        for(X=4;X<n;X<<=1);
        data=new T[X*2];
        fill(data,data+X*2,default_val);
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
        if(l!=r){
            T res=op(data[l+=X],data[r+=X]);
            while(l/2!=r/2){
                if(l%2==0)res=op(res,data[l+1]);
                if(r%2)res=op(res,data[r-1]);
                l>>=1;
                r>>=1;
            }
            return res;
        }
        else return data[l+X];
    }
};