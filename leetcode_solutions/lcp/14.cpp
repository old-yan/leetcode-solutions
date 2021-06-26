#include "EulerPrime.h"
#include "utils.h"

class Solution {
    int before[1000001];
public:
    int splitArray(vector<int>& nums) {
        static EulerPrime<1000000>ep;
        memset(before,0x3f,sizeof(before));
        int n=nums.size();
        int dp[n+1];
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        REP(i,nums.size()){
            ep.getPrimeFactors<0>(nums[i]);
            REP(_,ep.plen){
                int p=ep.pf[_];
                chmin(before[p],dp[i]);
                chmin(dp[i+1],before[p]+1);
            }
        }
        return dp[n];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,3,2,3,3};
    auto ans=sol.splitArray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
