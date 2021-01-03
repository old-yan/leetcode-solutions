#pragma once
#include <iostream>
#include <fstream>
#include <tuple>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <numeric>
using namespace std;

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
    ~Union(){
        delete []find;
        delete []size;
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