#include "utils.h"

class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(ALL(A));
        int ans=A.back()-A.front();
        REP(i,A.size()-1){
            chmin(ans,max(A[i]+K,A.back()-K)-min(A[i+1]-K,A.front()+K));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,3,6};
    int K=3;
    auto ans=sol.smallestRangeII(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
