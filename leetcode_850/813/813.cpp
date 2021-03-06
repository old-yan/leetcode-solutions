#include "utils.h"

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n=A.size();
        int cnt[n];
        REP(i,n)cnt[i]=i?cnt[i-1]+A[i]:A[i];
        double dp[n][K+1];
        fill(dp[0],dp[n],INT_MIN);
        REP(i,n){
            dp[i][1]=double(cnt[i])/(i+1);
        }
        FOR(i,1,n){
            FOR(j,2,K+1){
                REP(last,i){
                    chmax(dp[i][j],dp[last][j-1]+double(cnt[i]-cnt[last])/(i-last));
                }
            }
        }
        return dp[n-1][K];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{9,1,2,3,9};
    int K=3;
    auto ans=sol.largestSumOfAverages(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
