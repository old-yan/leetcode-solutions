#include "utils.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(abs(S)>1000)return 0;
        int dp[nums.size()][2001];
        memset(dp,0,sizeof(dp));
        #define a(m,n) (m<0?(n==1000?1:0):(n<0||n>2000?0:dp[m][n]))
        REP(i,nums.size()){
            int j=nums[i];
            REP(k,2001){
                dp[i][k]=a(i-1,k+j)+a(i-1,k-j);
            }
        }
        return dp[nums.size()-1][1000+S];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,1,1,1};
    int S=3;
    auto ans=sol.findTargetSumWays(nums,S);
    DBG(ans);

    system("pause");
    return 0;
}
