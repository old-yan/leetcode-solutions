#include <vector>
#include <bitset>
using namespace std;

//欧拉筛处理质数相关问题，range指定质数范围
template<int range>
struct EulerPrime{
    bool b[range+1]={0};
    int r,v[range]={0},lv,minf[range+1];
    EulerPrime():r(range),lv(0){
        b[0]=b[1]=true;
        minf[0]=minf[1]=0;
        for(int i=2;i<=range;i++){
            if(!b[i])minf[i]=v[lv++]=i;
            for(int j=0,k;(k=v[j]*i)<=r;j++){
                b[k]=true;
                minf[k]=v[j];
                if(i%v[j]==0)break;
            }
        }
    }
    //isPrime判断是否为质数
    bool isPrime(int n){
        if(n<2)return false;
        if(n<=r)return !b[n];
        for(int i=0,j;(j=v[i])&&j*j<=n;i++)if(n%j==0)return false;
        return true;
    }
    //getFactors分解质因数，dup参数表示是否存储重复的质因数
    template<int dup>
    vector<int>getFactors(int n){
        vector<int>res;
        auto fun=[&](int&n,int&j){
            if constexpr(dup){
                while(n%j==0){
                    res.push_back(j);
                    n/=j;
                }
            }
            else{
                res.push_back(j);
                while(n%j==0)n/=j;
            }
        };
        if(n>r){
            for(int i=0,j;(j=v[i])&&j*j<=n;i++)if(n%j==0)fun(n,j);
            if(n>1)res.push_back(n);
        }
        else{
            while(int j=minf[n])fun(n,j);
        }
        return res;
    }
};