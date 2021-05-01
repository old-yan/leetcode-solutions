#include "utils.h"

int _dp[301][11];
auto dp=_dp+1;
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(_dp,0x3f,sizeof(_dp));
        dp[-1][0]=0;
        int n=jobDifficulty.size();
        REP(i,n){
            FOR(j,1,d+1){
                int Max=0;
                REPR(k,i){
                    chmax(Max,jobDifficulty[k]);
                    chmin(dp[i][j],dp[k-1][j-1]+Max);
                }
            }
        }
        int ans=dp[n-1][d];
        return ans>=0x3f3f3f3f?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
