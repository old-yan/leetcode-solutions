#include "utils.h"

class Solution {
    int n,gcd[14][14];
    void init(vi&nums){
        n=nums.size();
        REP(i,n)REP(j,n){
            gcd[i][j]=mygcd(nums[i],nums[j]);
        }
    }
public:
    int maxScore(vector<int>& nums) {
        init(nums);
        ll dp[1<<n];
        memset(dp,0x80,sizeof(dp));
        dp[0]=0;
        FOR(state,1,1<<n)if(__builtin_popcount(state)%2==0){
            int i=__builtin_popcount(state)/2;
            for(int s=state;s;s=(s-1)&state)if(__builtin_popcount(s)==2){
                chmax(dp[state],dp[state-s]+i*gcd[__builtin_ctz(s)][31-__builtin_clz(s)]);
            }
        }
        return dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2};
    auto ans=sol.maxScore(nums);
    DBG(ans);

    system("pause");
    return 0;
}
