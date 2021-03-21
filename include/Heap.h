#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <functional>
using namespace std;
#define OLDYAN_HEAP

template<class T>
struct Heap{
    #define HEAPSIZE 10000
    typedef function<bool(T&,T&)> Operation;
    int Data[HEAPSIZE+1],Pos[HEAPSIZE+1]={0};
    unordered_map<T,int>M;
    vector<T>v;
    bitset<HEAPSIZE+1>pool;
    Operation cmp;
    Heap(Operation _cmp):cmp(_cmp){
        v.resize(HEAPSIZE+1);
        pool.set();pool.reset(0);
    }
    void push(T val){
        if(!M.count(val)){
            int idx=pool._Find_first();
            pool.reset(idx);
            M[val]=idx;
            v[idx]=val;
            Pos[idx]=M.size();
        }
        int idx=M[val];
        for(int cur=Pos[idx],parent;parent=cur>>1;cur=parent){
            if(cmp(v[Data[parent]],val))Pos[Data[cur]=Data[parent]]=cur;
            else{
                Pos[Data[cur]=idx]=cur;
                return;
            }
        }
        Pos[Data[1]=idx]=1;
    }
    void sink(T val){
        if(!M.count(val))return;
        int idx=M[val];
        int cur,son;
        for(cur=Pos[idx],son;(son=cur<<1)<=M.size();cur=son){
            if(son+1<=M.size()&&cmp(v[Data[son]],v[Data[son+1]]))son++;
            if(cmp(val,v[Data[son]]))Pos[Data[cur]=Data[son]]=cur;
            else{
                Pos[Data[cur]=idx]=cur;
                return;
            }
        }
        Pos[Data[cur]=idx]=cur;
    }
    void pop(){
        if(M.empty())return;
        pool.set(Data[1]);
        M.erase(v[Data[1]]);
        T val=v[Data[M.size()+1]];
        int idx=M[val],cur,son;
        for(cur=1,son;(son=cur<<1)<=M.size();cur=son){
            if(son+1<=M.size()&&cmp(v[Data[son]],v[Data[son+1]]))son++;
            if(cmp(val,v[Data[son]]))Pos[Data[cur]=Data[son]]=cur;
            else{
                Pos[Data[cur]=idx]=cur;
                return;
            }
        }
        Pos[Data[cur]=idx]=cur;
    }
    const T top(){
        return v[Data[1]];
    }
    const size_t size(){
        return M.size();
    }
};