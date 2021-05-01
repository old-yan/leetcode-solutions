#include "utils.h"

class Solution {
    vi fun(int n){
        if(n<10){
            vi res(50,0);
            REP(i,n+1)res[i]++;
            return res;
        }
        else{
            int m;
            for(m=n;m%10!=9;m--);
            auto res=fun(m/10);
            for(int i=49,j=49,k=0;i>=0;i--){
                while(j>=0&&j>i-10)k+=res[j--];
                k-=res[i];
                res[i]+=k;
            }
            while(n>m){
                int cnt=0;
                for(int i=n--;i;i/=10)cnt+=i%10;
                res[cnt]++;
            }
            return res;
        }
    }
public:
    int countLargestGroup(int n) {
        auto res=fun(n);
        res[0]=0;
        int Max=*max_element(ALL(res));
        int ans=0;
        REP(i,50)if(res[i]==Max)ans++;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=13;
    auto ans=sol.countLargestGroup(n);
    DBG(ans);

    system("pause");
    return 0;
}
