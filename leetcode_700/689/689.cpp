#include "utils.h"

class Solution {
    vi window_sum;
    vvi dp;
    vvi postMax;
    void fun(vi&ans,int l,int idx,int sum){
        if(l<0)return;
        for(int i=idx;;i++){
            if(dp[l][i]==sum){
                ans.pb(i);
                fun(ans,l-1,i+1,sum-window_sum[i]);
                return;
            }
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k*3)return {0,0,0};
        window_sum.resize(n,0);
        int sum=accumulate(nums.begin(),nums.begin()+k,0);
        REP(i,n-k+1){
            window_sum[i]=sum;
            if(i+k<n)sum+=nums[i+k]-nums[i];
        }
        dp.resize(3,vi(n,0));
        postMax.resize(3);
        dp[0]=window_sum;
        postMax[0]=postmax(window_sum);
        FOR(l,1,3){
            vi&v=postMax[l-1];
            #define a(i) (i<n?v[i]:0)
            REPR(i,n-k*l){
                dp[l][i]=window_sum[i]+a(i+k);
            }
            postMax[l]=postmax(dp[l]);
        }
        vi ans;
        fun(ans,2,0,postMax[2][0]);
        DBGVV(dp);
        DBGVV(postMax);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,1,2,6,7,5,1};
    int k=2;
    auto ans=sol.maxSumOfThreeSubarrays(nums,k);
    DBGV(ans);

    system("pause");
    return 0;
}
