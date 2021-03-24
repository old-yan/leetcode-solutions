#pragma once
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
    int data[TRIESIZE+1][TRIEN]={0};
    bitset<TRIESIZE+1>pool;
    StaticTrie(){
        data[0][26]=-1;
        data[0][27]=0;
        pool.set();
        pool.reset(0);
    }
    void clear(){
        memset(data,0,sizeof(data));
        data[0][26]=-1;
        pool.set();
        pool.reset(0);
    }
    int* operator[](int i){return data[i];}
    void Malloc(int&idx){
        idx=pool._Find_first();
        memset(data[idx],0,TRIEN*sizeof(int));
        data[idx][26]=-1;
        pool.reset(idx);
    }
    void Free(int&idx){
        pool.set(idx);
        idx=0;
    }
    int insert(int cur,const string&word,int i,int _signal) {
        int res=0;
        if(i==word.size()){
            if(data[cur][26]<0){
                data[cur][26]=_signal;
                res=1;
            }
        }
        else{
            if(!data[cur][word[i]-'a']){
                Malloc(data[cur][word[i]-'a']);
            }
            res=insert(data[cur][word[i]-'a'],word,i+1,_signal);
        }
        data[cur][27]+=res;
        return res;
    }
    void insert(const string&word,int _signal=1) {
        insert(0,word,0,_signal);
    }
    int search(const string&word) {
        int cur=0;
        for(int i=0;i<word.size();i++){
            if(!data[cur][word[i]-'a']){
                return -1;
            }
            cur=data[cur][word[i]-'a'];
        }
        return data[cur][26];
    }
    bool startsWith(const string&prefix) {
        int cur=0;
        for(int i=0;i<prefix.size();i++){
            if(!data[cur][prefix[i]-'a']){
                return false;
            }
            cur=data[cur][prefix[i]-'a'];
        }
        return true;
    }
    #undef TRIEN
    #undef TRIESIZE
};

//二叉字典树
class BiTrie {
    #define TRIESIZE 10000
    #define TRIEN 4
public:
    int data[TRIESIZE+1][TRIEN]={0},used;
    BiTrie():used(1){}
    void clear(){
        memset(data,0,sizeof(data));
        used=1;
    }
    void insert(int num){
        int cur=0;
        for(int i=31;i>=0;i--){
            int&next=data[cur][num>>i&1];
            if(!next)next=used++;
            cur=next;
        }
    }
    int searchMax(int num) {
        if(used==1)return 0;
        int cur=0,maxSame=0;
        for(int i=31;i>=0;i--){
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
    #undef TRIEN
    #undef TRIESIZE
};