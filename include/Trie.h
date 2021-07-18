#pragma once
#include <iostream>
#include <memory.h>
#include <bitset>
using namespace std;
#define OLDYAN_TRIE

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
    int insert(const string&word,int i,int _signal) {
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
    void insert(const string&word,int _signal=1) {
        insert(word,0,_signal);
    }
    int search(const string&word,int i) {
        if(i==word.size()){
            return signal;
        }
        else return child[word[i]-'a']?child[word[i]-'a']->search(word,i+1):-1;
    }
    int search(const string&word) {
        return search(word,0);
    }
    bool startsWith(const string&prefix) {
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
    #define TRIESIZE 10000
    #define TRIEN 30
public:
    int data[TRIESIZE+1][TRIEN]={0},cnt;
    StaticTrie(){
        cout<<"attention TRIESIZE,<="<<TRIESIZE<<'\n';
        clear();
    }
    void clear(){
        fill(data[0],data[1],0);
        data[0][26]=-1;
        cnt=1;
    }
    int* operator[](int i){return data[i];}
    void Malloc(int&idx){
        idx=cnt++;
        memset(data[idx],0,TRIEN*sizeof(int));
        data[idx][26]=-1;
    }
    void insert(const string&word,int signal=0){
        int cur=0;
        for(char c:word){
            if(!data[cur][c-'a'])Malloc(data[cur][c-'a']);
            cur=data[cur][c-'a'];
        }
        data[cur][26]=signal;
    }
    template<class iterator>
    void insert(iterator begin,iterator end,int signal=0){
        int cur=0;
        for(auto it=begin;it<end;++it){
            if(!data[cur][*it-'a'])Malloc(data[cur][*it-'a']);
            cur=data[cur][*it-'a'];
        }
        data[cur][26]=signal;
    }
    int search(const string&word) {
        int cur=0;
        for(char c:word){
            if(!data[cur][c-'a'])return -1;
            cur=data[cur][c-'a'];
        }
        return data[cur][26];
    }
    #undef TRIEN
    #undef TRIESIZE
};

//二叉字典树
template<int X=30>
struct BiTrie{
    #define TRIESIZE 2000000
    #define TRIEN 3
    int data[TRIESIZE+1][TRIEN]={0},used;
    BiTrie():used(1){}
    void clear(){
        memset(data[0],0,used*TRIEN*sizeof(int));
        used=1;
    }
    void insert(int num){
        int cur=0;
        for(int i=X;i>=0;i--){
            int&next=data[cur][num>>i&1];
            if(!next)next=used++;
            cur=next;
        }
    }
    void erase(int num){
        function<void(int&,int)>_erase=[&](int&cur,int i){
            if(!cur)return;
            if(i==0)cur=0;
            else{
                _erase(data[cur][num>>(i-1)&1],i-1);
                if(!data[cur][0]&&!data[cur][1])cur=0;
            }
        };
        _erase(data[0][num>>X&1],X);
    }
    int MaxXor(int num) {
        if(used==1)return 0;
        int cur=0,maxSame=0;
        for(int i=X;i>=0;i--){
            maxSame<<=1;
            int next=data[cur][num>>i&1];
            if(next){
                cur=next;
                maxSame++;
            }
            else cur=data[cur][!((num>>i)&1)];
        }
        return maxSame;
    }
};