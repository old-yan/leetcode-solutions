#include "utils.h"

class Solution {
    //使用数组ends收集所有的end时间，方便二分查找
    vi ends;
public:
    int maxValue(vector<vector<int>>& events, int k) {
        //dp[i][j]表示在下标范围0~i的事件中找j件事做，获得的最大值
        int dp[events.size()][k+1];
        memset(dp,0,sizeof(dp));
        //按照end升序排列
        sort(ALL(events),[&](vi&x,vi&y)->bool{return x[1]<y[1];});
        for(auto&A:events)ends.pb(A[1]);
        REP(i,events.size()){
            auto&A=events[i];
            int start=A[0],end=A[1],value=A[2];
            //用变量pos找到可以续接events[i]的位置
            int pos;
            {
                int low=0,high=i;
                while(low<high){
                    int mid=(low+high)/2;
                    if(ends[mid]>=start)high=mid;
                    else low=mid+1;
                }
                //二分找到low,low是第一件无法和events[i]并存的事件，即events[low][1]>=events[i][0]
                //那么low-1就是最后一件可以和events[i]并存的事件
                pos=low-1;
            }
            //pos小于0表示events[i]无法和之前事件并存，只能作为第一件事
            //所以只能尝试更新一件事的最大值，两件以上时放弃第i件事
            if(pos<0){
                FOR(j,1,k+1){
                    if(i)dp[i][j]=dp[i-1][j];
                    if(j==1)chmax(dp[i][1],value);
                }
            }
            //pos大于0时，在不做第i件事和做第i件事中选最大值
            else{
                FOR(j,1,k+1){
                    if(i)dp[i][j]=dp[i-1][j];
                    chmax(dp[i][j],dp[pos][j-1]+value);
                }
            }
        }
        int ans=0;
        //注意不一定做的事越多，值越大，所以要遍历
        FOR(j,1,k+1)chmax(ans,dp[events.size()-1][j]);
        return ans;
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi events{
        {1,2,4},{3,4,3},{2,3,10}
    };
    int k=2;
    auto ans=sol.maxValue(events,k);
    DBG(ans);

    system("pause");
    return 0;
}
