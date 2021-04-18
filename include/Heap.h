#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <functional>
using namespace std;
#define OLDYAN_HEAP

template<class T=int,int type=0>
struct Heap{
    #define HEAPSIZE 100
    typedef function<bool(const T&,const T&)> Operation;
    int Data[HEAPSIZE+1],Pos[HEAPSIZE+1]={0};
    unordered_map<T,int>M;
    vector<T>v;
    bitset<HEAPSIZE+1>pool;
    Operation cmp;
    Heap(Operation _cmp):cmp(_cmp){
        cout<<"attention HEAPSIZE,<="<<HEAPSIZE<<'\n';
        v.resize(HEAPSIZE+1);
        pool.set();
        pool.reset(0);
    }
    void push(const T&val){
        int idx,cur,parent;
        if(!M.count(val)){
            idx=pool._Find_first();
            pool.reset(idx);
            M[val]=idx;
            v[idx]=val;
            Pos[idx]=M.size();
        }
        else idx=M[val];
        for(cur=Pos[idx];parent=cur>>1;cur=parent){
            if(cmp(v[Data[parent]],val))Pos[Data[cur]=Data[parent]]=cur;
            else break;
        }
        Pos[Data[cur]=idx]=cur;
    }
    void sink(const T&val){
        if(!M.count(val))return;
        int idx=M[val],cur,son;
        for(cur=Pos[idx];(son=cur<<1)<=M.size();cur=son){
            if(son+1<=M.size()&&cmp(v[Data[son]],v[Data[son+1]]))son++;
            if(cmp(val,v[Data[son]]))Pos[Data[cur]=Data[son]]=cur;
            else break;
        }
        Pos[Data[cur]=idx]=cur;
    }
    void pop(){
        if(M.empty())return;
        pool.set(Data[1]);
        M.erase(v[Data[1]]);
        if(M.empty())return;
        T&val=v[Data[M.size()+1]];
        int idx=M[val],cur,son;
        for(cur=1;(son=cur<<1)<=M.size();cur=son){
            if(son+1<=M.size()&&cmp(v[Data[son]],v[Data[son+1]]))son++;
            if(cmp(val,v[Data[son]]))Pos[Data[cur]=Data[son]]=cur;
            else break;
        }
        Pos[Data[cur]=idx]=cur;
    }
    const T&top(){
        return v[Data[1]];
    }
    const size_t size(){
        return M.size();
    }
};
template<class T>
struct Heap<T,0>{
    #define HEAPSIZE 100
    typedef function<bool(int&,int&)> Operation;
    int Data[HEAPSIZE+1],Pos[HEAPSIZE+1]={0},Size;
    Operation cmp;
    Heap(Operation _cmp):cmp(_cmp),Size(0){
        cout<<"attention HEAPSIZE,<="<<HEAPSIZE<<'\n';
    }
    void push(int val){
        int cur,parent;
        if(!Pos[val])Pos[val]=++Size;
        for(cur=Pos[val];parent=cur>>1;cur=parent){
            if(cmp(Data[parent],val))Pos[Data[cur]=Data[parent]]=cur;
            else break;
        }
        Pos[Data[cur]=val]=cur;
    }
    void sink(int val){
        if(!Pos[val])return;
        int cur,son;
        for(cur=Pos[val];(son=cur<<1)<=Size;cur=son){
            if(son+1<=Size&&cmp(Data[son],Data[son+1]))son++;
            if(cmp(val,Data[son]))Pos[Data[cur]=Data[son]]=cur;
            else break;
        }
        Pos[Data[cur]=val]=cur;
    }
    void pop(){
        if(!Size)return;
        Pos[Data[1]]=0;
        if(!--Size)return;
        int val=Data[Size+1],cur,son;
        for(cur=1;(son=cur<<1)<=Size;cur=son){
            if(son+1<=Size&&cmp(Data[son],Data[son+1]))son++;
            if(cmp(val,Data[son]))Pos[Data[cur]=Data[son]]=cur;
            else break;
        }
        Pos[Data[cur]=val]=cur;
    }
    const int top(){
        return Data[1];
    }
    const size_t size(){
        return Size;
    }
};