#include "utils.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(),m=multipliers.size();
        ll dp[m+1][m+1];
        memset(dp,0x80,sizeof(dp));
        dp[0][0]=0;
        REP(i,m){
            REP(j,i+2){
                if(n-1-(i-j)<n)chmax(dp[i+1][j],dp[i][j]+(ll)multipliers[i]*nums[n-1-(i-j)]);
                if(j)chmax(dp[i+1][j],dp[i][j-1]+(ll)multipliers[i]*nums[j-1]);
            }
        }
        return *max_element(dp[m],dp[m+1]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    vi multipliers{3,2,1};
    auto ans=sol.maximumScore(nums,multipliers);
    DBG(ans);

    system("pause");
    return 0;
}
