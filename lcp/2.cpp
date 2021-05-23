#include "utils.h"

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        ll a=cont.back(),b=1;
        REPR(i,int(cont.size())-2){
            ll cur=cont[i];
            cur=a*cur+b;
            b=a;
            a=cur;
            cur=mygcd(a,b);
            a/=cur;
            b/=cur;
        }
        return {a,b};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi count{3,2,0,2};
    auto ans=sol.fraction(count);
    DBGV(ans);

    system("pause");
    return 0;
}
