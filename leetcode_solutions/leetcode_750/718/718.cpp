#include "utils.h"

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n1=A.size(),n2=B.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        int ans=0;
        REPR(i,n1-1){
            REPR(j,n2-1){
                if(A[i]==B[j]){
                    dp[i][j]=dp[i+1][j+1]+1;
                    chmax(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,3,2,1};
    vi B{3,2,1,4,7};
    auto ans=sol.findLength(A,B);

    system("pause");
    return 0;
}
