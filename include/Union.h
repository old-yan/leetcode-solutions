#pragma once
#include <memory.h>
#include <vector>
#include <numeric>
using namespace std;
#define OLDYAN_UNION

//并查集
class Union{
    #define UNIONSIZE 100000
public:
    int find[UNIONSIZE],size[UNIONSIZE],n,group;
    Union(int _n):n(_n),group(_n){
        iota(find,find+n,0);
        fill(size,size+n,1);
    }
    Union(const Union&other):n(other.n),group(other.group){
        memcpy(find,other.find,n*sizeof(int));
        memcpy(size,other.size,n*sizeof(int));
    }
    void reset(){
        iota(find,find+n,0);
        fill(size,size+n,1);
        group=n;
    }
    int Find(int i){
        if(find[i]==i)return i;
        else return find[i]=Find(find[i]);
    }
    bool unite(int i,int j){
        if((i=Find(i))==(j=Find(j)))return false;
        if(i<j){
            find[j]=i;
            size[i]+=size[j];
        }
        else{
            find[i]=j;
            size[j]+=size[i];
        }
        group--;
        return true;
    }
    bool same(int i,int j){
        return Find(i)==Find(j);
    }
};