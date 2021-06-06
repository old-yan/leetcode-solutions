#include "utils.h"

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int dp[1<<n];
        dp[0]=0;
        FOR(state,1,1<<n){
            dp[state]=INT_MAX;
            int k=__builtin_popcount(state);
            REP(j,n)if(state>>j&1){
                chmin(dp[state],dp[state-(1<<j)]+(nums1[k-1]^nums2[j]));
            }
        }
        return dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{1,0,3};
    vi nums2{5,3,4};
    auto ans=sol.minimumXORSum(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
