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

//动态字典树
class DynamicTrie {
public:
    DynamicTrie*child[26];
    int signal,num_of_son;
    DynamicTrie() {
        memset(child,0,sizeof(child));
        signal=-1;
        num_of_son=0;
    }
    ~DynamicTrie(){
        for(int i=0;i<26;i++){
            if(child[i])delete child[i];
        }
    }
    int insert(string&word,int i,int _signal) {
        int res=0;
        if(i==word.size()){
            if(signal<0){
                signal=_signal;
                ++res;
            }
        }
        else{
            if(!child[word[i]-'a']){
                child[word[i]-'a']=new DynamicTrie;
            }
            res=child[word[i]-'a']->insert(word,i+1,_signal);
        }
        num_of_son+=res;
        return res;
    }
    void insert(string&word,int _signal=1) {
        insert(word,0,_signal);
    }
    int search(string&word,int i) {
        if(i==word.size()){
            return signal;
        }
        else return child[word[i]-'a']?child[word[i]-'a']->search(word,i+1):-1;
    }
    int search(string&word) {
        return search(word,0);
    }
    bool startsWith(string&prefix) {
        auto p=this;
        for(char c:prefix){
            if(!p->child[c-'a']){
                return false;
            }
            p=p->child[c-'a'];
        }
        return true;
    }
};

//静态字典树
class StaticTrie {
    #define TRIEN 28
public:
    int*data,size;
    bitset<1<<18>pool;
    StaticTrie(int _size=1):size(_size) {
        data=(int*)malloc(size*TRIEN*sizeof(int));
        memset(data,0,size*TRIEN*sizeof(int));
        (*this)[0][27]=1;
        pool.set();
        pool.reset(0);
    }
    ~StaticTrie(){free(data);}
    int* operator[](int i){
        return data+i*TRIEN;
    }
    void Malloc(int&idx){
        int first=pool._Find_first();
        if(first>=size){
            int d=&idx-data;
            data=(int*)realloc(data,size*2*TRIEN*sizeof(int));
            memset((*this)[size],0,size*TRIEN*sizeof(int));
            size<<=1;
            data[d]=first;
            pool.reset(first);
        }
        else{
            idx=first;
            pool.reset(first);
        }
    }
    void Free(int&idx){
        pool.set(idx);
        idx=0;
    }
    int insert(int cur,string&word,int i,int _signal) {
        int res=0;
        if(i==word.size()){
            if(!(*this)[cur][26]){
                (*this)[cur][26]=_signal+1;
                ++res;
            }
        }
        else{
            if(!(*this)[cur][word[i]-'a']){
                Malloc((*this)[cur][word[i]-'a']);
            }
            res=insert((*this)[cur][word[i]-'a'],word,i+1,_signal);
        }
        (*this)[cur][27]+=res;
        return res;
    }
    void insert(string&word,int _signal=1) {
        insert(0,word,0,_signal);
    }
    int search(string&word) {
        int cur=0;
        for(int i=0;i<word.size();i++){
            if(!(*this)[cur][word[i]-'a']){
                return -1;
            }
            cur=(*this)[cur][word[i]-'a'];
        }
        return (*this)[cur][26]-1;
    }
    bool startsWith(string&prefix) {
        int cur=0;
        for(int i=0;i<prefix.size();i++){
            if(!(*this)[cur][prefix[i]-'a']){
                return false;
            }
            cur=(*this)[cur][prefix[i]-'a'];
        }
        return true;
    }
    #undef TRIEN
};