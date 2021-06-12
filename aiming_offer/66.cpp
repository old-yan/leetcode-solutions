#include "utils.h"

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        int preprod[n+2],postprod[n+1];
        preprod[0]=1;
        REP(i,n)preprod[i+1]=preprod[i]*a[i];
        postprod[n]=1;
        REPR(i,n-1)postprod[i]=postprod[i+1]*a[i];
        vi ans(n);
        REP(i,n){
            ans[i]=preprod[i]*postprod[i+1];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi a{1,2,3,4,5};
    auto ans=sol.constructArr(a);
    DBGV(ans);

    system("pause");
    return 0;
}
