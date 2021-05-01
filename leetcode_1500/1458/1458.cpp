#include "utils.h"

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int dp[2][m+1][n+1];
        fill(dp[0][0],dp[1][0],0);
        fill(dp[1][0],dp[2][0],INT_MIN);
        REP(i,m)REP(j,n){
            dp[1][i+1][j+1]=max(nums1[i]*nums2[j]+max(dp[0][i][j],dp[1][i][j]),max(dp[1][i][j+1],dp[1][i+1][j]));
        }
        return dp[1][m][n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{2,1,-2,5};
    vi nums2{3,0,-6};
    auto ans=sol.maxDotProduct(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
