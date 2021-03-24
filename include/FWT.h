#include <vector>
using namespace std;

//下标异或关系的向量卷积FWT算法
template<int forward,class T>
void FWT_xor(T v[],int n){
    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=(i<<1))for(int k=j;k<j+i;k++){
        int x=v[k],y=v[k+i];
        if constexpr(forward){v[k]=x+y,v[k+i]=x-y;}
        else{v[k]=(x+y)>>1,v[k+i]=(x-y)>>1;}
    }
}

//下标或关系的向量卷积FWT算法
template<int forward,class T>
void FWT_or(T v[],int n){
    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=(i<<1))for(int k=j;k<j+i;k++){
        if constexpr(forward)v[k+i]+=v[k];
        else v[k+i]-=v[k];
    }
}

//下标与关系的向量卷积FWT算法
template<int forward,class T>
void FWT_and(T v[],int n){
    for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=(i<<1))for(int k=j;k<j+i;k++){
        if constexpr(forward)v[k]+=v[k+i];
        else v[k]-=v[k+i];
    }
}
