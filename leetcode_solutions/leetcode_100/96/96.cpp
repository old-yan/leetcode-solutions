#include "utils.h"

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        REP(i,n+1){
            if(!i)dp[i]=1;
            else{
                dp[i]=0;
                FOR(j,1,i+1){
                    dp[i]+=dp[j-1]*dp[i-j];
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=20;
    auto ans=sol.numTrees(n);
    DBG(n);

    system("pause");
    return 0;
}
