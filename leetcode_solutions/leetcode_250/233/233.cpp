#include "utils.h"

class Solution {
    ll unit[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    ll count[10]={0,1,20,300,4000,50000,600000,7000000,80000000,900000000};
    int fun(ll n,int i){
        if(i<0)return 0;
        int j=n/unit[i];
        if(!j){
            return fun(n,i-1);
        }
        else if(j==1){
            return count[i]+n-unit[i]+1+fun(n%unit[i],i-1);
        }
        else{
            return count[i]*j+unit[i]+fun(n%unit[i],i-1);
        }
    }
public:
    int countDigitOne(int n) {
        return fun((ll)n,9);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=15;
    auto ans=sol.countDigitOne(n);
    DBG(ans);

    system("pause");
    return 0;
}
