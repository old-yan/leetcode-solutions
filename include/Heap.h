#pragma once
#include <iostream>
#include <functional>
using namespace std;
#define OLDYAN_HEAP

struct Heap{
    #define HEAPSIZE 10000
    typedef function<bool(int,int)> Operation;
    int Data[HEAPSIZE+1],Pos[HEAPSIZE+1]={0},Size;
    Operation cmp;
    Heap(Operation _cmp):Size(0),cmp(_cmp){}
    void push(int key){
        for(int cur=Pos[key]?Pos[key]:++Size,parent;parent=cur>>1;cur=parent){
            if(cmp(Data[parent],key))Pos[Data[cur]=Data[parent]]=cur;
            else{
                Pos[Data[cur]=key]=cur;
                return;
            }
        }
        Pos[Data[1]=key]=1;
    }
    void sink(int key){
        int cur,son;
        for(cur=Pos[key],son;(son=cur<<1)<=Size;cur=son){
            if(son+1<=Size&&cmp(Data[son],Data[son+1]))son++;
            if(cmp(key,Data[son]))Pos[Data[cur]=Data[son]]=cur;
            else{
                Pos[Data[cur]=key]=cur;
                return;
            }
        }
        Pos[Data[cur]=key]=cur;
    }
    void pop(){
        if(!Size)return;
        Pos[Data[1]]=0;
        int key=Data[Size--],cur,son;
        for(cur=1,son;(son=cur<<1)<=Size;cur=son){
            if(son+1<=Size&&cmp(Data[son],Data[son+1]))son++;
            if(cmp(key,Data[son]))Pos[Data[cur]=Data[son]]=cur;
            else{
                Pos[Data[cur]=key]=cur;
                return;
            }
        }
        Pos[Data[cur]=key]=cur;
    }
    const int top(){
        return Data[1];
    }
    const unsigned int size(){
        return Size;
    }
};