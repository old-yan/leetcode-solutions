#include <bitset>
#include <vector>
#include <stack>
#include <cmath>
#include <functional>
using namespace std;

//欧拉筛处理质数相关问题，range指定质数范围
template<int range>
struct EulerPrime{
    bool b[range+1]={0};
    int r,v[range]={0},lv,minf[range+1];
    int pf[50],pcnt[50],plen;//处理质因数专用数组
    int factors[1000],flen;//处理因数专用数组
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
    //getPrimeFactors分解质因数，dup参数表示是否存储重复的质因数
    //返回值存放在pf,pcnt数组里，pf按升序存放质因数，pcnt为对应质因数的次数，质因数总类数为plen
    template<int dup>
    void getPrimeFactors(long long n){
        plen=0;
        auto fun=[&](long long&n,int j){
            if constexpr(dup){
                int cnt=0;
                while(n%j==0){
                    cnt++;
                    n/=j;
                }
                pf[plen]=j;
                pcnt[plen++]=cnt;
            }
            else{
                pf[plen++]=j;
                while(n%j==0)n/=j;
            }
        };
        if(n>r){
            for(int i=0,j,end=sqrt(n);(j=v[i])&&j<=end;i++)if(n%j==0)fun(n,j);
            if(n>1)fun(n,n);
        }
        else{
            while(int j=minf[n])fun(n,j);
        }
    }
    void dfs(int cur,long long curp){
        if(cur==plen)factors[flen++]=curp;
        else{
            for(int i=pcnt[cur],j=pf[cur];i>=0;i--,curp*=j)dfs(cur+1,curp);
        }
    }
    //getFactors获取所有的因数
    //返回值存放在factors数组里，质因数总数为flen
    void getFactors(long long n){
        flen=0;
        getPrimeFactors<1>(n);
        stack<tuple<int,long long,int>>S;
        S.emplace(0,1,0);
        while(S.size()){
            auto [cur,curp,i]=S.top();
            S.pop();
            if(i>pcnt[cur]){
                if(S.size())S.
            }
        }


        dfs(0,1);
    }
};