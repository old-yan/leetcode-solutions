#include "utils.h"

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int dp[A.size()][2];
        #define dp(i,j) (i>=0?dp[i][j]:!j)
        REP(i,A.size()){
            if(A[i]>R)dp[i][0]=dp[i][1]=0;
            else if(A[i]>=L){
                dp[i][0]=0;
                dp[i][1]=dp(i-1,0)+dp(i-1,1)+1;
            }
            else{
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1];
            }
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,1,4,3};
    int L=2;
    int R=3;
    auto ans=sol.numSubarrayBoundedMax(A,L,R);
    DBG(ans);

    system("pause");
    return 0;
}
