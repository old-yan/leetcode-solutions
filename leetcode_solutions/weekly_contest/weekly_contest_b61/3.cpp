#include "utils.h"

class Solution {
public:
    //本题是典型动态规划，但是是从一个区间转移到一个点
    //  如果使用线段树统计出区间最大值会非常方便
    //  当然没有线段树也是可以做的，时间复杂度还更低
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m=rides.size();
        //将乘客按照 end 进行升序排序，这样处理某个顾客的时候，他之前的顾客肯定已经处理完毕
        sort(ALL(rides),[](auto&x,auto&y){return x[1]<y[1];});
        //dp[t]表示截止t时间，车子的最大收益
        ll dp[n+1];
        memset(dp,0,sizeof(dp));
        //使用premax来记录dp的前缀最大值，premax[i] 表示 dp[0~i] 的最大值
        vector<ll>premax{0};
        for(auto&r:rides){
            int start=r[0],end=r[1],tip=r[2];
            while(premax.size()<=start){
                premax.push_back(max(premax.back(),dp[premax.size()]));
            }
            //从 dp[0~start] 里找个最大值，然后再把当前顾客接上，来更新dp[end]
            ll Max=premax[start];
            dp[end]=max(dp[end],Max+(end-start+tip));
        }
        return *max_element(dp,dp+n+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=20;
    vvi rides=makevvi("[[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]");
    auto ans=sol.maxTaxiEarnings(n,rides);
    DBG(ans);

    system("pause");
    return 0;
}