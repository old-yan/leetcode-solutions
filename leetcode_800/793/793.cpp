#include "utils.h"

class Solution {
    ll fun(ll n){
        int res=0;
        for(ll i=5;i<=n;i*=5){
            res+=n/i;
        }
        return res;
    }
public:
    int preimageSizeFZF(int K) {
        ll n1,n2;
        {
            ll low=0,high=4100000000;
            while(low<high){
                ll mid=(low+high)/2;
                if(fun(mid)>=K)high=mid;
                else low=mid+1;
            }
            n1=low;
        }
        {
            ll low=0,high=4100000000;
            while(low<high){
                ll mid=(low+high)/2;
                if(fun(mid)>K)high=mid;
                else low=mid+1;
            }
            n2=low;
        }
        return n2-n1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int K=5;
    auto ans=sol.preimageSizeFZF(K);
    DBG(ans);

    system("pause");
    return 0;
}
