#include "EulerPrime.h"
#include "utils.h"

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int l1 = A.size(), l2 = B.size();
        int dp[l1+1][l2+1];
        memset(dp,0,sizeof(dp));
        REP(i,l1){
            REP(j,l2){
                dp[i+1][j+1]=A[i]==B[j]?dp[i][j]+1:max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[l1][l2];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,4,2};
    vi B{1,2,4};
    auto ans=sol.maxUncrossedLines(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
