#include "utils.h"

class Solution {
    ll n;
    ll ans=0;
    void fun(int l){
        ll low=2,high=n;
        ll val;
        bool in_limit;
        auto getval=[&](ll base){
            val=0;
            in_limit=true;
            REP(i,l){
                if(val>=LLONG_MAX/base){
                    in_limit=false;
                    break;
                }
                val=val*base+1;
            }
        };
        while(low<high){
            ll mid=(low+high)/2;
            getval(mid);
            if(!in_limit||val>=n)high=mid;
            else low=mid+1;
        }
        getval(low);
        if(in_limit&&val==n)ans=low;
    }
public:
    string smallestGoodBase(string _n) {
        n=s2i(_n);
        FORR(l,63,2){
            fun(l);
            if(ans)return i2s(ans);
        }
        return _n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string n="13";//13*(3-1)+1=27
    auto ans=sol.smallestGoodBase(n);
    DBG(ans);

    system("pause");
    return 0;
}
