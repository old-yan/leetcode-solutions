#include<iostream>
#include<memory.h>
using namespace std;

// 后缀数组，生成sa，rk数组
#define SASIZE 1000000
template<class T=string,int range=128>
struct SuffixArray{
    int n,bucketRange;
    int sa[SASIZE],second[SASIZE],bucket[SASIZE],mem[SASIZE],rk_mem[SASIZE+1],rk2_mem[SASIZE+1],height[SASIZE];
    int *rk,*rk2;
    void reset(const T&s){
        n=s.size(),bucketRange=range,rk=rk_mem,rk2=rk2_mem;
        rk[n]=rk2[n]=-1;
        memset(bucket,0,range*sizeof(int));
        for(int i=0;i<n;i++)bucket[rk[i]=s[i]]++;
        for(int i=1;i<bucketRange;i++)bucket[i]+=bucket[i-1];
        for(int i=0;i<n;i++)sa[--bucket[rk[i]]]=i;
        for(int w=1;;w<<=1){
            int j=0;
            for(int i=n-w;i<n;i++)second[j++]=i;
            for(int i=0;i<n;i++)if(sa[i]>=w)second[j++]=sa[i]-w;
            memset(bucket,0,bucketRange*sizeof(int));
            for(int i=0;i<n;i++)bucket[mem[i]=rk[second[i]]]++;
            for(int i=1;i<bucketRange;i++)bucket[i]+=bucket[i-1];
            for(int i=n-1;i>=0;i--)sa[--bucket[mem[i]]]=second[i];
            bucketRange=0;
            for(int i=0;i<n;i++){
                rk2[sa[i]]=!i||(rk[sa[i]]==rk[sa[i-1]]&&rk[sa[i]+w]==rk[sa[i-1]+w])?bucketRange:++bucketRange;
            }
            swap(rk,rk2);
            if(++bucketRange==n)break;
        }
        memset(height,0xff,n*sizeof(int));
        for(int i=0,h=0;i<n;i++){
            if(h)h--;
            if(rk[i])while(sa[rk[i]-1]+h<n&&s[i+h]==s[sa[rk[i]-1]+h])h++;
            height[rk[i]]=h;
        }
    }
};