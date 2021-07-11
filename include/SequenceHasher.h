#include<iostream>
#include<memory.h>
using namespace std;

// 字符串哈希助手，快速查询区间哈希值
template<class T=string,int B=233,int M=1000000007,int range=100000>
struct SequenceHasher{
    T s;
    long long n,units[range+1],val[range+1],rval[range+1];
    StringHasher(const T&_s):s(_s),n(s.size()){
        for(int i=0;i<=n;i++)units[i]=i?units[i-1]*B%M:1;
        for(int i=0;i<=n;i++)val[i]=i?(val[i-1]*B+s[i-1])%M:0;
        for(int i=0;i<=n;i++)rval[n-i]=i?(rval[n-i+1]*B+s[n-i])%M:0;
    }
    long long ask(int begin,int end){//begin<=end
        return (val[end+1]+(M-val[begin])*units[end-begin+1])%M;
    }
    long long rask(int begin,int end){//begin>=end
        return (rval[end]-(M-rval[begin+1])*units[begin-end+1])%M;
    }
};