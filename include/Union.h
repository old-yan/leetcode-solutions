#pragma once
#include <memory.h>
#include <vector>
#include <numeric>
using namespace std;
#define OLDYAN_UNION

//并查集
class Union{
public:
    int*find;
    int*size;
    int n;
    int group;
    Union(int _n):n(_n),group(_n){
        find=new int[n];
        iota(find,find+n,0);
        size=new int[n];
        fill(size,size+n,1);
    }
    Union(const Union&other):n(other.n),group(other.group){
        find=new int[n];
        memcpy(find,other.find,n*sizeof(int));
        size=new int[n];
        memcpy(size,other.size,n*sizeof(int));
    }
    ~Union(){
        delete []find;
        delete []size;
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
        i=Find(i);
        j=Find(j);
        if(i==j)return false;
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