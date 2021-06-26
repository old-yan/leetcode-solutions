#include "utils.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<ll>res;
        res.pb(1);
        ll times[3]={2,3,5};
        ll cursor[3]={0,0,0};
        ll prod[3]={2,3,5};
        while(res.size()<n){
            int opt=min_element(prod,prod+3)-prod;
            if(prod[opt]>res.back())res.pb(prod[opt]);
            cursor[opt]++;
            prod[opt]=res[cursor[opt]]*times[opt];
        }
        return res[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.nthUglyNumber(n);
    DBG(ans);

    system("pause");
    return 0;
}
