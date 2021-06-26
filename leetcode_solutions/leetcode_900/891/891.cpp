#include "utils.h"

class Solution {
    ll res[20001]={0};
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(ALL(A));
        FORR(i,A.size()-2,0){
            ll d=A[i+1]-A[i];
            res[i]=(res[i+1]*2+d*(twoPower[A.size()-i-1]-1))%MOD;
        }
        return accumulate(res,res+20001,0ll)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,1,3};
    auto ans=sol.sumSubseqWidths(A);
    DBG(ans);

    system("pause");
    return 0;
}
