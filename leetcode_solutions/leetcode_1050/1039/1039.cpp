#include "utils.h"

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int ans=INT_MAX;
        FOR(i,2,n){
            REP(j,n){
                int k=(j+i)%n;
                int jj=(j+1)%n;
                int kk=(k+n-1)%n;
                dp[j][k]=INT_MAX;
                for(int l=jj,_=i-1;_--;l=(l+1)%n){
                    chmin(dp[j][k],values[j]*values[k]*values[l]+dp[j][l]+dp[l][k]);
                }
                if(i==n-1)chmin(ans,dp[j][k]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi values{1,3,1,4,1,5};
    auto ans=sol.minScoreTriangulation(values);
    DBG(ans);

    system("pause");
    return 0;
}
