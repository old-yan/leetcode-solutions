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
    #define TRIEN
public:
    int*data,size;
    bitset<1<<18>pool;
    StaticTrie(int _size=1):size(_size){
        data=(int*)malloc(size*TRIEN*sizeof(int));
        memset(data,0,size*TRIEN*sizeof(int));
        (*this)[0][26]=-1;
        (*this)[0][27]=0;
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
            size<<=1;
            data[d]=first;
        }
        else idx=first;
        memset((*this)[first],0,TRIEN*sizeof(int));
        (*this)[first][26]=-1;
        pool.reset(first);
    }
    void Free(int&idx){
        pool.set(idx);
        idx=0;
    }
    int insert(int cur,const string&word,int i,int _signal) {
        int res=0;
        if(i==word.size()){
            if((*this)[cur][26]<0){
                (*this)[cur][26]=_signal;
                res=1;
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
    void insert(const string&word,int _signal=1) {
        insert(0,word,0,_signal);
    }
    int search(const string&word) {
        int cur=0;
        for(int i=0;i<word.size();i++){
            if(!(*this)[cur][word[i]-'a']){
                return -1;
            }
            cur=(*this)[cur][word[i]-'a'];
        }
        return (*this)[cur][26]>=0;
    }
    bool startsWith(const string&prefix) {
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

//二叉字典树
class BiTrie {
    #define TRIEN 2
public:
    int*data,used,default_val;
    BiTrie(int size=1,int _default_val=0):used(1),default_val(_default_val){
        int count=1,j=1;
        for(int i=0;i<32;i++){
            j=min(j*2,size);
            count+=j;
        }
        data=(int*)malloc(count*TRIEN*sizeof(int));
        memset(data,0,count*TRIEN*sizeof(int));
    }
    ~BiTrie(){free(data);}
    void insert(int num){
        int cur=0;
        for(int i=31;i>=0;i--){
            int&next=data[cur*TRIEN+((num>>i)&1)];
            if(!next)next=used++;
            cur=next;
        }
    }
    int searchMax(int num) {
        if(used==1)return default_val;
        int cur=0,maxSame=0;
        for(int i=31;i>=0;i--){
            maxSame<<=1;
            int next=data[cur*TRIEN+((num>>i)&1)];
            if(next){
                cur=next;
                maxSame++;
            }
            else cur=data[cur*TRIEN+!((num>>i)&1)];
        }
        return maxSame;
    }
    #undef TRIEN
};