#include "utils.h"

class Solution {
public:
    //本题需要想清楚动态规划的转移方式：
    //设dp[i]表示，当前已经把[0,i-1]范围内的石头移除了，现在放了一块新石头（且新石头价值等于原[0,i-1]区间石头的值的和）
    //  那么，当前玩家可以获取的最大相对收益。
    //那么，当前玩家除了必须拿走新石头，还至少得拿一块石头。
    //假定拿走新石头+[i,j]区间，那么，相对收益 = presum(0,j)-dp[j+1]
    //于是，我们找到了让相对收益dp[i]最大的方法，那就是在自己的右边找个下标j，令下标j处的presum(0,j)-dp[j+1]最大
    //不妨设dp2[j]=presum(0,j)-dp[j+1]
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        ll presum[n+1];
        presum[0]=0;
        partial_sum(ALL(stones),presum+1);
        ll dp[n+1];
        dp[n]=0;
        ll j=presum[n];
        REPR(i,n-1){
            chmax(j,presum[i+1]-dp[i+1]);
            dp[i]=j;
        }
        return dp[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi stones{-1,2,-3,4,-5};
    auto ans=sol.stoneGameVIII((stones));
    DBG(ans);

    system("pause");
    return 0;
}
