#include<iostream>
#include<memory.h>
using namespace std;

// 后缀数组，生成sa，rk数组
struct SuffixArray{
    #define MAXN 10000
    string s;
    int n,bucketRange;
    int sa[MAXN],second[MAXN],bucket[MAXN],mem[MAXN],rk_mem[MAXN],rk2_mem[MAXN],height[MAXN];
    int *rk,*rk2;
    SuffixArray(const string&_s):s(_s),n(s.size()),bucketRange(127){
        cout<<"attention MAXN,string length<="<<MAXN-1<<'\n';
        rk=rk_mem;
        rk2=rk2_mem;
        rk[n]=rk2[n]=-1;
        memset(bucket,0,sizeof(bucket));
        for(int i=0;i<n;i++)bucket[rk[i]=s[i]]++;
        for(int i=1;i<=bucketRange;i++)bucket[i]+=bucket[i-1];
        for(int i=0;i<n;i++)sa[--bucket[rk[i]]]=i;
        for(int w=1;;w<<=1){
            int j=0;
            for(int i=n-w;i<n;i++)second[j++]=i;
            for(int i=0;i<n;i++)if(sa[i]>=w)second[j++]=sa[i]-w;
            memset(bucket,0,sizeof(bucket));
            for(int i=0;i<n;i++)bucket[mem[i]=rk[second[i]]]++;
            for(int i=1;i<=bucketRange;i++)bucket[i]+=bucket[i-1];
            for(int i=n-1;i>=0;i--)sa[--bucket[mem[i]]]=second[i];
            bucketRange=0;
            for(int i=0;i<n;i++){
                rk2[sa[i]]=!i||(rk[sa[i]]==rk[sa[i-1]]&&rk[sa[i]+w]==rk[sa[i-1]+w])?bucketRange:++bucketRange;
            }
            swap(rk,rk2);
            if(bucketRange==n-1)break;
        }
    }
    void getHeight(){
        memset(height,0xff,sizeof(height));
        for(int i=0,h=0;i<n;i++){
            if(h)h--;
            if(rk[i])while(s[i+h]==s[sa[rk[i]-1]+h])h++;
            height[rk[i]]=h;
        }
    }
    #undef MAXN
};