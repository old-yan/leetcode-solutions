#include "utils.h"

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size(),cur,Max=INT_MIN,Min=0;
        REP(i,n){
            cur=i?max(cur,0)+A[i]:A[i];
            chmax(Max,cur);
        }
        FOR(i,1,n){
            cur=i>1?min(cur,0)+A[i]:A[i];
            chmin(Min,cur);
        }
        return max(Max,accumulate(ALL(A),0)-Min);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,-2,3,-2};
    auto ans=sol.maxSubarraySumCircular(A);
    DBG(ans);

    system("pause");
    return 0;
}
