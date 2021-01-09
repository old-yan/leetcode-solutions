#include "utils.h"

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        ll total=0;
        for(int a:A)total+=a;
        ll F=0;
        REP(i,A.size())F+=i*A[i];
        ll ans=F;
        FOR(i,1,A.size()){
            F+=total;
            F-=A[A.size()-i]*A.size();
            chmax(ans,F);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{4,3,2,6};
    auto ans=sol.maxRotateFunction(A);
    DBG(ans);

    system("pause");
    return 0;
}
