#include "utils.h"

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int dp[n][2];
        #define dp(i,j) (i>=0?dp[i][j]:0)
        #define A(i) (i>=0?A[i]:-1)
        #define B(i) (i>=0?B[i]:-1)
        REP(i,A.size()){
            int c=A[i],d=B[i];
            if(min(c,d)>max(A(i-1),B(i-1))){
                dp[i][0]=min(dp(i-1,0),dp(i-1,1))+(c<d);
                dp[i][1]=min(dp(i-1,0),dp(i-1,1))+(c>d);
            }
            else{
                dp[i][0]=dp(i-1,0)+(c<d);
                dp[i][1]=dp(i-1,1)+(c>d);
            }
        }
        return min(dp[n-1][0],dp[n-1][1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,3,5,4};
    vi B{1,2,3,7};
    auto ans=sol.minSwap(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
