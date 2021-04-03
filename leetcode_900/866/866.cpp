#include "utils.h"

EulerPrime<10000>ep;
class Solution {
    int unit[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int N,ans;
    bool dfs(int val,int idx,int len){
        if(val<N-N%unit[idx])return false;
        if(!idx--){
            if(ep.isPrime(val)){
                ans=val;
                return true;
            }
            else return false;
        }
        if(idx<len/2){
            return dfs(val+unit[idx]*(val/unit[len-1-idx]%10),idx,len);
        }
        else if(val){
            for(int i=0;i<10;i++){
                if(dfs(val+i*unit[idx],idx,len))return true;
            }
        }
        else{
            for(int i=1;i<10;i++){
                if(dfs(val+i*unit[idx],idx,len))return true;
            }
        }
        return false;
    }
public:
    int primePalindrome(int _N) {
        N=_N;
        int len=i2s(N).size();
        while(!dfs(0,len,len))len++;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=6;
    auto ans=sol.primePalindrome(N);
    DBG(ans);

    system("pause");
    return 0;
}
